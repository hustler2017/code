#include "pch.h"
#include "Picker.h"
#include <directxcollision.h>

namespace Engine
{
	using namespace DirectX;

	Picker::Picker(Graphics::Direct3D* d3d, Camera* camera, Liner* liner)
	: m_d3d(d3d), m_camera(camera), m_liner(liner)
	{}
	Picker::~Picker(){}


	using namespace DirectX;

	void Picker::getPickLine(
		float x,
		float y,
		XMVECTOR& rayOrigin,
		XMVECTOR& rayDirection
	)
	{
		using namespace DirectX;

		Vector3 direction;

		XMFLOAT4X4 projMatrix;
		XMMATRIX inverseViewXMMatrix;
		XMFLOAT4X4 inverseViewFMatrix;

		inverseViewXMMatrix = XMMatrixInverse(0, m_camera->getViewMatrix());
		XMStoreFloat4x4(&inverseViewFMatrix, inverseViewXMMatrix);
		XMStoreFloat4x4(&projMatrix, m_camera->getProjectionMatrix());

		float pointX = ((2.0f * (float)x) / (float)m_d3d->getClientWidth()) - 1.0f;
		float pointY = (((2.0f * (float)y) / (float)m_d3d->getClientHeight()) - 1.0f) * -1.0f;

		pointX = pointX / projMatrix._11;
		pointY = pointY / projMatrix._22;

		direction.x = (pointX * inverseViewFMatrix._11) + (pointY * inverseViewFMatrix._21) + inverseViewFMatrix._31;
		direction.y = (pointX * inverseViewFMatrix._12) + (pointY * inverseViewFMatrix._22) + inverseViewFMatrix._32;
		direction.z = (pointX * inverseViewFMatrix._13) + (pointY * inverseViewFMatrix._23) + inverseViewFMatrix._33;

		Vector3 to = m_camera->getPosition();

		to.x += direction.x * 200;
		to.y += direction.y * 200;
		to.z += direction.z * 200;

		m_liner->addLine("picklines", m_camera->getPosition(), to, Vector4(1,0,0,1));

		rayOrigin = XMVectorSet(m_camera->getPosition().x, m_camera->getPosition().y, m_camera->getPosition().z, 1.0f);
		rayDirection = XMVectorSet(direction.x, direction.y, direction.z, 1.0f);
	}


	bool Picker::intersectObject(Object* object, XMVECTOR rayOrigin, XMVECTOR rayDirection)
	{
		AABB* aabb = object->getModel()->getAABB();
		Position* position = object->getPosition();

		return intersectAABB(aabb, position, rayOrigin, rayDirection);
	}

	bool Picker::intersectAABB(
		AABB* aabb,
		Position* position,
		XMVECTOR rayOrigin,
		XMVECTOR rayDirection
	)
	{
		using namespace DirectX;

		float distance;

		XMMATRIX objWorldMatrix = XMMatrixScaling(position->scale.x, position->scale.y, position->scale.z)
			* XMMatrixRotationRollPitchYaw(position->rotation.x, position->rotation.y, position->rotation.z)
			* XMMatrixTranslation(position->position.x, position->position.y, position->position.z);

		XMMATRIX inverseObjectWorldMatrix = XMMatrixInverse(0, objWorldMatrix);

		rayOrigin = XMVector3Transform(rayOrigin, inverseObjectWorldMatrix);
		rayDirection = XMVector3TransformNormal(rayDirection, inverseObjectWorldMatrix);
		rayDirection = XMVector3Normalize(rayDirection);

		BoundingBox bbox;
		BoundingBox::CreateFromPoints(bbox,
			XMVectorSet(aabb->points[0].x, aabb->points[0].y, aabb->points[0].z, 1),
			XMVectorSet(aabb->points[1].x, aabb->points[1].y, aabb->points[1].z, 1)
		);

		return bbox.Intersects(rayOrigin, rayDirection, distance);
	}


	bool Picker::intersectMesh(
		Mesh* mesh,
		Position* position,
		XMVECTOR rayOrigin,
		XMVECTOR rayDirection,
		Vector3& intersectionPoint
	)
	{
		using namespace DirectX;

		float distance;

		IVertexData* data = mesh->getVertexData();
		UINT num_polygons = data->getPolygonCount();

		if (num_polygons == 0) 
			return false;

		XMMATRIX objWorldMatrix = XMMatrixScaling(position->scale.x, position->scale.y, position->scale.z)
			* XMMatrixRotationRollPitchYaw(position->rotation.x, position->rotation.y, position->rotation.z)
			* XMMatrixTranslation(position->position.x, position->position.y, position->position.z);

		XMMATRIX inverseObjectWorldMatrix = XMMatrixInverse(0, objWorldMatrix);

		rayOrigin = XMVector3Transform(rayOrigin, inverseObjectWorldMatrix);
		rayDirection = XMVector3TransformNormal(rayDirection, inverseObjectWorldMatrix);
		rayDirection = XMVector3Normalize(rayDirection);

		Vector3 v1,v2,v3;
		for (int p = 0; p < num_polygons; p++)
		{
			v1 = data->getCoordinates(data->getPolygonVertex(p, 2));
			v2 = data->getCoordinates(data->getPolygonVertex(p, 1));
			v3 = data->getCoordinates(data->getPolygonVertex(p, 0));

			if (TriangleTests::Intersects(
				rayOrigin,
				rayDirection,
				XMVectorSet(v1.x, v1.y, v1.z, 1),
				XMVectorSet(v2.x, v2.y, v2.z, 1),
				XMVectorSet(v3.x, v2.y, v3.z, 1),
				distance
			))
			{
				intersectionPoint.x = XMVectorGetX(rayOrigin + rayDirection * distance);
				intersectionPoint.y = XMVectorGetY(rayOrigin + rayDirection * distance);
				return true;
			}
		}

		return false;
	}

	Object* Picker::getPickedObject(std::list<Object*>* objects, int x, int y)
	{
		using namespace DirectX;

		XMVECTOR rayOrigin;
		XMVECTOR rayDirection;

		getPickLine(x, y, rayOrigin, rayDirection);

		for (const auto& object : *objects)
		{
			if (intersectAABB(
				object->getModel()->getAABB(),
				object->getPosition(),
				rayOrigin,
				rayDirection
			)) return object;
		}
		
		return nullptr;
	}

	Agent* Picker::getPickedAgent(std::list<Agent*>* agents, int x, int y)
	{
		using namespace DirectX;

		XMVECTOR rayOrigin;
		XMVECTOR rayDirection;

		getPickLine(x, y, rayOrigin, rayDirection);

		for (const auto& agent : *agents)
		{
			if (intersectAABB(
				agent->getModel()->getAABB(),
				agent->getPosition(),
				rayOrigin,
				rayDirection
			)) return agent;
		}

		return nullptr;
	}


	bool Picker::getPickedMesh(Mesh* mesh, Engine::Position position, int x, int y, float& xi, float& yi)
	{
		using namespace DirectX;

		XMVECTOR rayOrigin;
		XMVECTOR rayDirection;

		getPickLine(x, y, rayOrigin, rayDirection);

		Vector3 intersectionPoint;
		Engine::Position pos;

		if (intersectMesh(mesh, &pos, rayOrigin, rayDirection, intersectionPoint))
		{
			xi = intersectionPoint.x;
			yi = intersectionPoint.y;



			return true;
		}

		return false;
	}
}