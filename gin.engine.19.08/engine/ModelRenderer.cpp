#include "pch.h"
#include "ModelRenderer.h"

namespace Engine
{

	ModelRenderer::ModelRenderer(Graphics::Direct3D* d3d)
	{
		m_d3d = d3d;
	}

	ModelRenderer::~ModelRenderer()
	{

	}

	void ModelRenderer::render(Model* model, int count)
	{
		m_d3d->pContext->PSSetShaderResources(0, model->getTexturesCount(), model->getTextures());
		m_d3d->pContext->IASetVertexBuffers(1, 1, model->mesh->getVertexBuffer(), model->mesh->getStride(), 0);

		m_d3d->pContext->DrawInstanced(model->mesh->getVertexCount(), count, 0, 0);
	}
}
