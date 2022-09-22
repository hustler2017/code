#include "pch.h"
#include "LinesRenderer.h"
#include "ShaderHelper.h"


namespace Engine
{	
	LinesRenderer::LinesRenderer(Graphics::Direct3D* d3d, LinesShader* shader)
		: m_shader(shader), m_d3d(d3d), m_buffer(nullptr), lines_counter(0), lines_max(40000)
	{
		m_resources = new LinesShaderResources2();
		m_buffer = new Line[lines_max];
		ShaderHelper::createVertexBuffer(d3d->pDevice, &m_resources->m_pVertexBuffer, nullptr, sizeof(Line) * lines_max);
	}

	LinesRenderer::~LinesRenderer()
	{
		if(m_buffer)
			delete[] m_buffer;

		if(m_resources)
			delete m_resources;
	}

	void LinesRenderer::updateResources()
	{
		m_d3d->pContext->UpdateSubresource(m_resources->m_pVertexBuffer, 0, 0, m_buffer, 0, 0);
	}

	void LinesRenderer::addLine(Vector3 from, Vector3 to, Vector4 color)
	{
		if (lines_counter < lines_max)
		{
			m_buffer[lines_counter].from.coordinates = from;
			m_buffer[lines_counter].from.color = color;
			m_buffer[lines_counter].to.coordinates = to;
			m_buffer[lines_counter].to.color = color;
			lines_counter++;
			m_resources->m_vertexCount = lines_counter * 2;
		}
	}
	void LinesRenderer::render()
	{
		if (lines_counter)
		{
			updateResources();
			m_shader->render(m_resources);
		}
	}
	void LinesRenderer::clear()
	{
		lines_counter = 0;
	}
}