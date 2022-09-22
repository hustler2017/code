#pragma once
#include "pch.h"
#include "Shader.h"
#include "IEngineSettings.h"
#include "TerrainShaderResources.h"


namespace Engine
{
	class TerrainShader : public Shader, public IMeshShader
	{
	public:
		TerrainShader(Graphics::Direct3D* d3d, IEngineSettings* settings);
		~TerrainShader();
		void render(Mesh* mesh);
		void createResources(Mesh* mesh);
		std::string getName();
	};
}

