#pragma once
#include "pch.h"

namespace Engine
{
	class SpriteShaderResources
	{
        friend class Sprite2DShader;
        friend class Sprite3DShader;

        ID3D11Buffer* pVertexBuffer;
        ID3D11Buffer* pInstanceBuffer;

        std::vector<ID3D11ShaderResourceView*> textures;

        int num_sprites;

    public:

        SpriteShaderResources(IShader* shader);
        ~SpriteShaderResources();

        void Release();

        IShader* getShader();

	};
}



