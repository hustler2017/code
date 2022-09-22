#pragma once

#include <map>
#include <string>
#include "IMeshShaderResources.h"

namespace Engine
{
	class BaseMesh
	{
	protected:
		std::map<std::string, IMeshShaderResources*>  m_resources;
	public:
		IMeshShaderResources* getShaderResources(std::string key);
		void setShaderResources(IMeshShaderResources* resources, std::string key);
	};
}


