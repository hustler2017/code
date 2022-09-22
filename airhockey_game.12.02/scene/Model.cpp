#include "pch.h"
#include "Scene3D.h"

namespace Scene3D {


	void inline Model::updateMatrix()
	{
		mx = mxRotation * mxTranslation;
	}

	void Model::setPosition(float x, float y, float z)
	{
		position = { x, y, z };

		updateMatrix();
	}

	void Model::setRotation(float x, float y, float z)
	{
		rotation = { x, y, z };
		updateMatrix();
	}

	void Model::rotate(float x, float y, float z)
	{
		
		rotation.x += x;
		rotation.y += y;
		rotation.z += z;

		mxRotation = XMMatrixRotationX(rotation.x) * XMMatrixRotationY(rotation.y) * XMMatrixRotationZ(rotation.z);
		updateMatrix();
	}

	void Model::move(float x, float y, float z)
	{
		position.x += x;
		position.y += y;
		position.z += z;
		mxTranslation = XMMatrixTranslation(position.x, position.y, position.z);
		updateMatrix();
	}

	Model::~Model()
	{

	}


	Mesh::~Mesh()
	{
		SafeRelease(dxIndexBuffer);
		SafeRelease(dxVertexBuffer);
	}


}