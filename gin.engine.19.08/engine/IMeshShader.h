#pragma once

#include "Mesh.h"
#include <string>

namespace Engine
{
    class Mesh;

    class IMeshShader
    {
    public:
        virtual void createResources(Mesh* mesh) = 0;
        virtual void render(Mesh* mesh) = 0;
        virtual std::string getName() = 0;
        virtual ~IMeshShader() {}
    };
}

