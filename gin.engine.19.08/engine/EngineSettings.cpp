#include "pch.h"
#include "EngineSettings.h"

namespace Engine
{
	std::wstring EngineSettings::getPath(std::wstring name)
	{
		return m_paths[name];
	}

	void EngineSettings::setPath(std::wstring name, std::wstring path)
	{
		m_paths[name] = path;
	}
}