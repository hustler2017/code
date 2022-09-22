#pragma once

#include "Common.h"
#include "Shader.h"
#include "IEngineSettings.h"

namespace Engine
{
    class SpriteShader : public Shader
    {
        struct Vertex
        {
            Vector3 coordinates;
            Vector3 position;
            Vector2 uv;
            int tex_id;
        };


        struct SpriteData
        {
            Vertex verticies[6];
        };

        SpriteData* sprites_buffer;

        int max_sprites_count;
        int max_textures_count;
        bool need_update;

        ID3D11Buffer* m_pVertexBuffer;

        std::vector<ID3D11ShaderResourceView*> m_textures;
        int num_sprites;

        int addTexture(ID3D11ShaderResourceView* texture);
        inline void setSprite(SpriteData* sprite, Vector3 position, float left, float top, float right, float bottom, UINT tex_id);
        void updateResources();
    public:
        SpriteShader(Graphics::Direct3D* d3d, IEngineSettings* settings);
        ~SpriteShader();
        void render();
        bool addSprite(Vector4 rect, Vector3 position, ID3D11ShaderResourceView* texture);
        void clear();
    };

}

