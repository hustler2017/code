#pragma once
#include "pch.h"
#include "IShader.h"

namespace Engine
{
	class IShader;

	class IShaderResources
	{
	public:
		virtual void Release() = 0;
		virtual IShader* getShader() = 0;
		virtual ~IShaderResources() {};
	};
}
