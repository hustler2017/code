#pragma once

#include "IMeshShader.h"

namespace Engine
{
	class IMeshShaderResources
	{
	public:
		virtual void Release() = 0;
		virtual void update() = 0;
		//virtual IMeshShader* getShader() = 0;
		virtual ~IMeshShaderResources() {};
	};
}

