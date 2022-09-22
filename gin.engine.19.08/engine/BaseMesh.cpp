#include "pch.h"
#include "BaseMesh.h"

namespace Engine
{
	IMeshShaderResources* BaseMesh::getShaderResources(std::string key)
	{
		auto it = m_resources.find(key);

		if (it != m_resources.end())
		{
			return it->second;
		}

		return nullptr;
	}


	void BaseMesh::setShaderResources(IMeshShaderResources* resources, std::string key)
	{
		auto it = m_resources.find(key);

		if (it != m_resources.end())
		{
			delete it->second;
			it->second = resources;
		}

		m_resources.insert({ key , resources });
	}
}