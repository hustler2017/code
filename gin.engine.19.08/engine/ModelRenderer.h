#pragma once
#include "Direct3D.h"
#include "Model.h"


namespace Engine
{

	class ModelRenderer
	{

		Graphics::Direct3D* m_d3d;

	public:
		ModelRenderer(Graphics::Direct3D* d3d);
		~ModelRenderer();

		void render(Model* m, int count);
	};

}

