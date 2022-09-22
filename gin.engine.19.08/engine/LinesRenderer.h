#pragma once

#include "LinesShader.h"
#include <list>

namespace Engine
{
	class LinesRenderer
	{
	private:
		Graphics::Direct3D* m_d3d;
		LinesShader* m_shader;
		LinesShaderResources2* m_resources;

		struct Line
		{
			LinesShaderResources2::Vertex from;
			LinesShaderResources2::Vertex to;
		};

		Line* m_buffer;
		int lines_counter;
		int lines_max;
	public:
		LinesRenderer(Graphics::Direct3D* d3d, LinesShader* shader);
		~LinesRenderer();

		void updateResources();

		void addLine(Vector3 from, Vector3 to, Vector4 color);
		void render();
		void clear();
	};
}
