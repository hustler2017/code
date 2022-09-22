#include "pch.h"
#include "SpriteShader.h"
#include "ShaderHelper.h"

namespace Engine
{
	SpriteShader::SpriteShader(Graphics::Direct3D* d3d, IEngineSettings* settings) : Shader(d3d)
	{
		max_sprites_count = 10000;
		max_textures_count = 10;

		sprites_buffer = new SpriteData[max_sprites_count];

		m_shaderFileName = settings->getPath(L"shaders") + std::wstring(L"sprite3d_shader.fx");
		m_vertexShaderFuncName = "vertexShader";
		m_pixelShaderFuncName = "pixelShader";

		D3D11_INPUT_ELEMENT_DESC layoutDesc[] = {
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "POSITION", 1, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXID", 0, DXGI_FORMAT_R32_UINT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};

		m_layoutDesc = new InputLayoutDesc(layoutDesc, 4);

		ShaderHelper::createVertexBuffer(m_d3d->pDevice, &m_pVertexBuffer, nullptr, sizeof(SpriteData) * max_sprites_count);

		load();
	}

	SpriteShader::~SpriteShader()
	{
		SAFE_RELEASE(m_pVertexBuffer);

		delete[] sprites_buffer;

		delete m_layoutDesc;
	}


	void SpriteShader::updateResources()
	{
		m_d3d->pContext->UpdateSubresource(m_pVertexBuffer, 0, 0, sprites_buffer, 0, 0);
		need_update = false; 
	}

	int SpriteShader::addTexture(ID3D11ShaderResourceView* texture)
	{
		int textures_count = m_textures.size();
		for (int i = 0; i < textures_count; i++)
		{
			if (m_textures[i] == texture)
				return i;
		}

		if (textures_count < max_textures_count)
		{
			m_textures.push_back(texture);
			return textures_count;
		}

		return -1;
	}


	void SpriteShader::setSprite(SpriteData* sprite, Vector3 position, float left, float top, float right, float bottom, UINT tex_id)
	{

		sprite->verticies[0].coordinates.x = left;
		sprite->verticies[0].coordinates.y = bottom;
		sprite->verticies[0].position = position;
		sprite->verticies[0].uv.x = 0;
		sprite->verticies[0].uv.y = 0;
		sprite->verticies[0].tex_id = tex_id;

		sprite->verticies[1].coordinates.x = left;
		sprite->verticies[1].coordinates.y = top;
		sprite->verticies[1].position = position;
		sprite->verticies[1].uv.x = 0;
		sprite->verticies[1].uv.y = 1;
		sprite->verticies[1].tex_id = tex_id;

		sprite->verticies[2].coordinates.x = right;
		sprite->verticies[2].coordinates.y = top;
		sprite->verticies[2].position = position;
		sprite->verticies[2].uv.x = 1;
		sprite->verticies[2].uv.y = 1;
		sprite->verticies[2].tex_id = tex_id;

		sprite->verticies[3].coordinates.x = left;
		sprite->verticies[3].coordinates.y = bottom;
		sprite->verticies[3].position = position;
		sprite->verticies[3].uv.x = 0;
		sprite->verticies[3].uv.y = 0;
		sprite->verticies[3].tex_id = tex_id;

		sprite->verticies[4].coordinates.x = right;
		sprite->verticies[4].coordinates.y = top;
		sprite->verticies[4].position = position;
		sprite->verticies[4].uv.x = 1;
		sprite->verticies[4].uv.y = 1;
		sprite->verticies[4].tex_id = tex_id;

		sprite->verticies[5].coordinates.x = right;
		sprite->verticies[5].coordinates.y = bottom;
		sprite->verticies[5].position = position;
		sprite->verticies[5].uv.x = 1;
		sprite->verticies[5].uv.y = 0;
		sprite->verticies[5].tex_id = tex_id;

	}

	bool SpriteShader::addSprite(Vector4 rect, Vector3 position, ID3D11ShaderResourceView* texture)
	{
		if (num_sprites < max_sprites_count)
		{
			int tex_id = addTexture(texture);
			if (tex_id >= 0) {
				SpriteData* sprite = &sprites_buffer[num_sprites];
				setSprite(sprite, position, rect.x, rect.y, rect.z, rect.w, static_cast<UINT>(tex_id));
				num_sprites++;
				need_update = true;
				return true;
			}
		}

		return false;
	}

	void SpriteShader::render()
	{
		if (num_sprites == 0) return;

		if (need_update)
		{
			updateResources();
		}

		UINT strides[] = { sizeof(Vertex) };
		UINT offset[] = { 0,0 };

		ID3D11Buffer* buffers[] = { m_pVertexBuffer  };

		m_d3d->pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		m_d3d->pContext->IASetInputLayout(m_pInputLayout);
		m_d3d->pContext->VSSetShader(m_pVertexShader, 0, 0);
		m_d3d->pContext->PSSetShader(m_pPixelShader, 0, 0);
		m_d3d->pContext->IASetVertexBuffers(0, 1, buffers, strides, offset);
		m_d3d->pContext->PSSetShaderResources(0, m_textures.size(), &m_textures[0]);
		m_d3d->pContext->Draw(num_sprites * 6, 0);
	}



	void SpriteShader::clear()
	{
		num_sprites = 0;
		m_textures.clear();
	}
}