#include "pch.h"
#include "Sprite2DShader.h"

namespace Engine
{
	Sprite2DShader::Sprite2DShader(Graphics::Direct3D* d3d, IEngineSettings* settings) : Shader(d3d)
    {
		max_sprites_count = 10;
		max_textures_count = 10;

		sprites_buffer = new SpriteData[max_sprites_count];
		instanceData = new InstanceData[max_sprites_count];

		m_shaderFileName = settings->getPath(L"shaders") + std::wstring(L"sprite2d_shader.fx");
		m_vertexShaderFuncName = "vertexShader";
		m_pixelShaderFuncName = "pixelShader";

		D3D11_INPUT_ELEMENT_DESC layoutDesc[] = {
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXID", 0, DXGI_FORMAT_R32G32B32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};

		m_layoutDesc = new InputLayoutDesc(layoutDesc, 3);

		load();

		createResources();

    }
    
	Sprite2DShader::~Sprite2DShader()
    {
		delete[] sprites_buffer;
		delete[] instanceData;

		delete m_layoutDesc;

		if (m_resources) 
			delete m_resources;
    }

	void Sprite2DShader::createResources()
    {
		m_resources = new SpriteShaderResources(this);

		m_resources->num_sprites = 0;

		try {

			{
				D3D11_BUFFER_DESC bufferDesc;
				bufferDesc.Usage = D3D11_USAGE_DEFAULT;
				bufferDesc.ByteWidth = max_sprites_count * sizeof(SpriteData);
				bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
				bufferDesc.CPUAccessFlags = 0;
				bufferDesc.MiscFlags = 0;

				if (FAILED(m_d3d->pDevice->CreateBuffer(&bufferDesc, 0, &m_resources->pVertexBuffer)))
				{
					OutputDebugString(L"SpriteShader: Не удалось создать вершинный буфер.");
					throw false;
				}
			}

			{
				D3D11_BUFFER_DESC bufferDesc;
				bufferDesc.Usage = D3D11_USAGE_DEFAULT;
				bufferDesc.ByteWidth = max_sprites_count * sizeof(InstanceData);
				bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
				bufferDesc.CPUAccessFlags = 0;
				bufferDesc.MiscFlags = 0;

				if (FAILED(m_d3d->pDevice->CreateBuffer(&bufferDesc, 0, &m_resources->pInstanceBuffer)))
				{
					OutputDebugString(L"SpriteShader: Не удалось создать буфер экземпляров.");
					throw false;
				}
			}
		}
		catch (bool)
		{
			delete m_resources;
		}
		
		need_update = true;
    }

	void Sprite2DShader::updateResources()
	{
		m_d3d->pContext->UpdateSubresource(m_resources->pVertexBuffer, 0, 0, sprites_buffer, 0, 0);
		m_d3d->pContext->UpdateSubresource(m_resources->pInstanceBuffer, 0, 0, instanceData, 0, 0);
	}

	void Sprite2DShader::renderResources(IShaderResources* resources)
	{
		SpriteShaderResources* res = dynamic_cast<SpriteShaderResources*>(resources);
		renderResources(res);
	}

	int Sprite2DShader::addTexture(ID3D11ShaderResourceView* texture)
	{
		int textures_count = m_resources->textures.size();
		for (int i = 0; i < textures_count; i++)
		{
			if (m_resources->textures[i] == texture)
				return i;
		}

		if (textures_count < max_textures_count)
		{
			m_resources->textures.push_back(texture);
			return textures_count;
		}

		return -1;
	}

    void Sprite2DShader::renderResources(SpriteShaderResources* resources)
    {
		UINT strides[] = { sizeof(Vertex), sizeof(InstanceData) };
		UINT offset[] = { 0,0 };

		ID3D11Buffer* buffers[] = { resources->pVertexBuffer , resources->pInstanceBuffer };

		m_d3d->pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		m_d3d->pContext->IASetInputLayout(m_pInputLayout);
		m_d3d->pContext->VSSetShader(m_pVertexShader, 0, 0);
		m_d3d->pContext->PSSetShader(m_pPixelShader, 0, 0);
		m_d3d->pContext->IASetVertexBuffers(0, 2, buffers, strides, offset);
		m_d3d->pContext->PSSetShaderResources(0, 1, &resources->textures[0]);
		m_d3d->pContext->DrawInstanced(6, resources->num_sprites, 0, 0);
    }

	void Sprite2DShader::setSprite(SpriteData* sprite, float left, float top, float right, float bottom, UINT tex_id)
	{
		sprite->verticies[0].coordinates.x = left;
		sprite->verticies[0].coordinates.y = bottom;
		sprite->verticies[0].uv.x = 0;
		sprite->verticies[0].uv.y = 0;

		sprite->verticies[1].coordinates.x = left;
		sprite->verticies[1].coordinates.y = top;
		sprite->verticies[0].uv.x = 0;
		sprite->verticies[0].uv.y = 1;

		sprite->verticies[2].coordinates.x = right;
		sprite->verticies[2].coordinates.y = top;
		sprite->verticies[0].uv.x = 1;
		sprite->verticies[0].uv.y = 1;

		sprite->verticies[3].coordinates.x = left;
		sprite->verticies[3].coordinates.y = bottom;
		sprite->verticies[0].uv.x = 0;
		sprite->verticies[0].uv.y = 0;

		sprite->verticies[4].coordinates.x = right;
		sprite->verticies[4].coordinates.y = top;
		sprite->verticies[0].uv.x = 1;
		sprite->verticies[0].uv.y = 1;

		sprite->verticies[5].coordinates.x = right;
		sprite->verticies[5].coordinates.y = bottom;
		sprite->verticies[0].uv.x = 1;
		sprite->verticies[0].uv.y = 0;
	}

	bool Sprite2DShader::addSprite(int left, int top, int right, int bottom, ID3D11ShaderResourceView* texture)
	{
		if (m_resources->num_sprites < max_sprites_count)
		{
			int tex_id = addTexture(texture);
			if (tex_id >= 0) {
				SpriteData* sprite = &sprites_buffer[m_resources->num_sprites++];
				setSprite( sprite,
					static_cast<float>(left),
					static_cast<float>(top),
					static_cast<float>(right),
					static_cast<float>(bottom),
					static_cast<UINT>(tex_id)
				);
				need_update = true;
				return true;
			}			
		}

		return false;
	}

	void Sprite2DShader::render()
	{
		if (m_resources)
		{
			if (m_resources->num_sprites)
			{
				if (need_update)
				{
					updateResources();
				}

				renderResources(m_resources);
			}
		}
	}

	void Sprite2DShader::clear()
	{
		m_resources->num_sprites = 0;
		m_resources->textures.clear();
	}
}
