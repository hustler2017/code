#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "AABB.h"
#include "LinesShader.h"

namespace Engine
{
	class AABBRenderer
	{
	private:
		Mesh* m_mesh;
		LinesShader* m_shader;
	private:
		void updateData(AABB* aabb);
	public:
		AABBRenderer(LinesShader* sh);
		~AABBRenderer();
		void render(AABB* aabb);
	};
}
