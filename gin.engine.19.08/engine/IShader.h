#pragma once
#include "pch.h"
#include "IShaderResources.h"

namespace Engine
{
	class IShaderResources;

	class IShader
	{
	public:
		virtual void renderResources(IShaderResources* resources) = 0;
		virtual ~IShader() {};
	};

}

