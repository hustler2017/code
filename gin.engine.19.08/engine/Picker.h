#pragma once

#include "Camera.h"
#include "Direct3D.h"
#include "AABB.h"
#include "Object.h"
#include "Agent.h"
#include "Terrain.h"
#include "Liner.h"

namespace Engine
{
	using namespace DirectX;

	class Picker
	{
		Camera* m_camera;
		Graphics::Direct3D* m_d3d;
		Liner* m_liner;

	public:
		Picker(Graphics::Direct3D* d3d, Camera* camera, Liner* liner);
		~Picker();

		Object* getPickedObject(std::list<Object*>* objects, int x, int y);
		Agent* getPickedAgent(std::list<Agent*>* agents, int x, int y);
		
		bool getPickedMesh(Mesh* mesh, Engine::Position position, int x, int y, float& xi, float& yi);


		void getPickLine(
			float x,
			float y,
			XMVECTOR& rayOrigin,
			XMVECTOR& rayDirection
		);

		bool intersectObject(
			Object* object,
			XMVECTOR rayOrigin,
			XMVECTOR rayDirection
		);

		bool intersectAABB(
			AABB* aabb,
			Position* position,
			XMVECTOR rayOrigin,
			XMVECTOR rayDirection
		);

		bool intersectMesh(
			Mesh* mesh,
			Position* position,
			XMVECTOR rayOrigin,
			XMVECTOR rayDirection,
			Vector3& intersectionPoint
		);
	};
}

