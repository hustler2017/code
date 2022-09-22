#include "pch.h"
#include "SpriteRenderer.h"




SpriteRenderer::SpriteRenderer(Graphics::Direct3D* d3d)
	: m_d3d(d3d)
{
	m_sprites_max_count = 256;
	m_verticies_count = 0;
	m_verticies_max_count = m_sprites_max_count * 6;
	m_verticies = new Vertex[m_verticies_max_count];
	m_buffer_pointer = m_verticies;
	m_instance_buffer = new InstanceData[m_sprites_max_count];
	m_instance_buffer_pointer = m_instance_buffer;

	createResources();
}

SpriteRenderer::~SpriteRenderer()
{
	delete[] m_verticies;
	delete[] m_instance_buffer;
}

int SpriteRenderer::addTexture(ID3D11ShaderResourceView* texture)
{
	for (int i = 0; i < m_textures.size(); i++)
	{
		if (m_textures[i] == texture)
		{
			return i;
		}
	}

	m_textures.push_back(texture);
	return m_textures.size() - 1;

}

void SpriteRenderer::addVertex(float x, float y, float u, float v)
{
	m_buffer_pointer->x = x;
	m_buffer_pointer->y = y;
	m_buffer_pointer->z = 0;
	m_buffer_pointer->u = u;
	m_buffer_pointer->v = v;
	m_buffer_pointer++;
	m_verticies_count++;
}

void SpriteRenderer::addQuad(SpriteRect rect)
{
	addVertex(rect.left_x, rect.bottom_y, 0,1);
	addVertex(rect.left_x, rect.top_y, 0, 0);
	addVertex(rect.right_x, rect.top_y, 1, 0);
	addVertex(rect.left_x, rect.bottom_y, 0,1);
	addVertex(rect.right_x, rect.top_y, 1,0);
	addVertex(rect.right_x, rect.bottom_y, 1,1);
}

void SpriteRenderer::addPosition(SpritePosition pos)
{
	m_instance_buffer_pointer->x = pos.x;
	m_instance_buffer_pointer->y = pos.y;
	m_instance_buffer_pointer->z = pos.z;
}

void SpriteRenderer::addSprite(SpriteRect rect, SpritePosition pos, ID3D11ShaderResourceView* texture)
{
	addQuad(rect);
	addPosition(pos);

	m_instance_buffer_pointer->texture_ind = addTexture(texture);

	m_instance_buffer_pointer++;
	m_sprites_count++;
}

void SpriteRenderer::render()
{
	UINT strides[] = { sizeof(Vertex), sizeof(InstanceData) };
	UINT offset[] = { 0,0 };

	ID3D11Buffer* buffers[] = { m_pVertexBuffer , m_pInstanceBuffer };

	m_shader->setup();

	m_d3d->pContext->IASetVertexBuffers(0, 2, buffers, strides, offset);
	m_d3d->pContext->PSSetShaderResources(0, 1, &m_textures[0]);
	m_d3d->pContext->UpdateSubresource(m_pVertexBuffer, 0, 0, m_verticies, 0, 0);
	m_d3d->pContext->UpdateSubresource(m_pInstanceBuffer, 0, 0, m_instance_buffer, 0, 0);
	m_d3d->pContext->DrawInstanced(6, m_sprites_count, 0, 0);
}

void SpriteRenderer::clear()
{

}

void SpriteRenderer::createInstanceBuffer()
{
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeof(InstanceData) * m_sprites_max_count;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	m_d3d->pDevice->CreateBuffer(&bufferDesc, nullptr, &m_pInstanceBuffer);
}

void SpriteRenderer::createBuffer()
{
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = m_verticies_max_count * sizeof(Vertex);
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA data;
	data.SysMemPitch = 0;
	data.SysMemSlicePitch = 0;
	data.pSysMem = m_verticies;

	m_d3d->pDevice->CreateBuffer(&bufferDesc, &data, &m_pVertexBuffer);
}

void SpriteRenderer::createResources()
{
	createBuffer();
	createInstanceBuffer();

	m_shader = new SpriteRendererShader(m_d3d);
}

void SpriteRenderer::freeResources()
{
	if (m_shader)
	{
		delete m_shader;
		m_shader = nullptr;
	}

	if (m_pVertexBuffer)
	{
		m_pVertexBuffer->Release();
		m_pVertexBuffer = nullptr;
	}

	if (m_pInstanceBuffer)
	{
		m_pInstanceBuffer->Release();
		m_pInstanceBuffer = nullptr;
	}
}