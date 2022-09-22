#pragma once
#include "pch.h"
#include "Shader.h"
#include "IMeshShader.h"
#include "Mesh.h"
#include "IEngineSettings.h"

#define MAX_MATRICES 30

namespace Engine
{
	class AnimatedMeshShader : public Shader, public IMeshShader
	{
		ID3D11Buffer* m_pConstantBuffer;
		void createConstantBuffer();
	public:
		AnimatedMeshShader(Graphics::Direct3D* d3d, IEngineSettings* settings);
		~AnimatedMeshShader();

		void createResources(Mesh* mesh);
		void render(Mesh* mesh);

		std::string getName();
		
	};
}

