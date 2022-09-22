#pragma once
#include "pch.h"
#include "Common.h"
#include "Mesh.h"
#include "MeshShaderResources.h"
#include "AnimatedMeshShader.h"
#include "ShaderHelper.h"


#define MAX_WEIGHTS 4

namespace Engine
{
	

	class AnimatedMeshShaderResources : public MeshShaderResources
	{
		friend class AnimatedMeshShader;

		struct Vertex {
			Vector3 position;
			Vector3 normal;
			Vector2 uv;
			unsigned int bone_id[MAX_WEIGHTS];
			float weight[MAX_WEIGHTS];
		};

		ID3D11Buffer* m_pVertexBuffer;
		int m_vertexCount;
		Vertex* data;
		Mesh* m_source;

		void createData();
	public:
		AnimatedMeshShaderResources(Graphics::Direct3D* d3d, Mesh* mesh);
		~AnimatedMeshShaderResources();

		void Release();
		void UpdateSubresource();
		
		ID3D11Buffer* getVertexBuffer();
		UINT getStride();
		UINT getVertexCount();
		void update();

	};

}

