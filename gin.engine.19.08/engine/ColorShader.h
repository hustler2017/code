#pragma once
#include "pch.h"
#include "Shader.h"
#include "IMeshShader.h"
#include "IEngineSettings.h"

namespace Engine {
    class ColorShader : public Shader, public IMeshShader
    {
    public:
        ColorShader(Graphics::Direct3D* d3d, IEngineSettings* settings);
        ~ColorShader();
        void createResources(Mesh* mesh);
        void render(Mesh* mesh);
        std::string getName();
        
    };
}

