#include "pch.h"
#include "SpriteShaderResources.h"


namespace Engine
{
    SpriteShaderResources::SpriteShaderResources(IShader* shader) : parent_shader(shader) {
        pVertexBuffer = nullptr;
        pInstanceBuffer = nullptr;
        num_sprites = 0;
    }

    SpriteShaderResources::~SpriteShaderResources()
    {
        Release();
    }

    void SpriteShaderResources::Release()
    {
        SAFE_RELEASE(pVertexBuffer);
        SAFE_RELEASE(pInstanceBuffer);
    }

    IShader* SpriteShaderResources::getShader()
    {
        return parent_shader;
    }
}