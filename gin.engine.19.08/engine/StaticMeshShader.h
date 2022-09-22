#pragma once
#include "pch.h"
#include "Shader.h"
#include "IMeshShader.h" 
#include "IEngineSettings.h"

namespace Engine
{
    class StaticMeshShader : public Shader, public IMeshShader
    {
    public:
        StaticMeshShader(Graphics::Direct3D* d3d, IEngineSettings* settings);
        ~StaticMeshShader();

        void createResources(Mesh* mesh);
        void render(Mesh* mesh);
        std::string getName();
    };
}
