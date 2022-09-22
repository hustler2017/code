#pragma once
#include "pch.h"
#include "Shader.h"
#include "Mesh.h"
#include "Direct3D.h"
#include "IEngineSettings.h"
#include "LinesShaderResources2.h"

namespace Engine
{
    class LinesShader : public Shader, public IMeshShader
    {        
    public:
        LinesShader(Graphics::Direct3D* d3d, IEngineSettings* settings);
        ~LinesShader();

        void createResources(Mesh* mesh);
        void render(Mesh* mesh);
        void render(LinesShaderResources2* res);
        std::string getName();
    };
}

