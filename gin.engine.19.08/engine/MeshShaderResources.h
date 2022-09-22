#pragma once
#include "IMeshShaderResources.h"
#include "Direct3D.h"
#include "Mesh.h"

namespace Engine
{
	class MeshShaderResources : public IMeshShaderResources
	{
	protected:
		Graphics::Direct3D* m_d3d;
		Mesh* m_mesh;
	public:
		MeshShaderResources(Graphics::Direct3D* d3d, Mesh* mesh)
			: m_mesh(mesh), m_d3d(d3d) {}

		void update() {};

		void Release() {};
	};
}



