#pragma once
#include "pch.h"
#include "Shader.h"




namespace Engine
{

	class SpriteRendererShader : public Shader
	{
	public:
		SpriteRendererShader(Graphics::Direct3D* d3d);
		~SpriteRendererShader();
		void setup();
	};

}