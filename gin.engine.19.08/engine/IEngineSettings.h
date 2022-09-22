#pragma once
#include "pch.h"
#include <string>

namespace Engine
{
	class IEngineSettings
	{
	public:
		virtual std::wstring getPath(std::wstring name) = 0;
		virtual void setPath(std::wstring name, std::wstring path) = 0;
		virtual HWND getHWnd() = 0;
	};
}

