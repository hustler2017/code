#pragma once
#include "pch.h"

#include "Direct3D.h"
#include "Object.h"

#include "PositionsBuffer.h"
#include "AABBRenderer.h"

namespace Engine
{
	class ObjectsRenderer
	{
	private:
		Graphics::Direct3D* m_d3d;

		//void renderModels(Model* model, int count);

	public:
		ObjectsRenderer(Graphics::Direct3D* d3d);
		~ObjectsRenderer();

		void render(Object* obj);
	};
}
