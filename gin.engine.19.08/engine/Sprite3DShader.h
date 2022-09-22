#pragma once
#include "Shader.h"
#include "SpriteShaderResources.h"
#include "IEngineSettings.h"

namespace Engine
{
    class Sprite3DShader : public Shader
    {
        struct Vertex
        {
            Vector3 coordinates;
            Vector2 uv;
        };

        struct InstanceData
        {
            Vector3 position;
            int tex_id;
        };

        struct SpriteData
        {
            Vertex verticies[6];
        };

        SpriteData* sprites_buffer;
        InstanceData* instanceData;

        SpriteShaderResources* m_resources;

        int max_sprites_count;
        int max_textures_count;
        bool need_update;

        void createResources();
        void updateResources();
        void renderResources(SpriteShaderResources* resources);
        int addTexture(ID3D11ShaderResourceView* texture);
        inline void setSprite(SpriteData* sprite, float left, float top, float right, float bottom, UINT tex_id);
    public:
        Sprite3DShader(Graphics::Direct3D* d3d, IEngineSettings* settings);
        ~Sprite3DShader();
        void renderResources(IShaderResources* resources);
        bool addSprite(Vector4 coords, Vector3 position, ID3D11ShaderResourceView* texture);

        void render();
        void clear();

    };
}

