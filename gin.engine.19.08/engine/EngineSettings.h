#pragma once
#include "pch.h"
#include "IEngineSettings.h"
#include <map>
namespace Engine
{
    class EngineSettings : public IEngineSettings
    {
        HWND m_hWnd;
        std::map<std::wstring, std::wstring> m_paths;
    public:
        void setHWnd(HWND hWnd) { m_hWnd = hWnd; }
        HWND getHWnd() { return m_hWnd; }
        std::wstring getPath(std::wstring name);
        void setPath(std::wstring name, std::wstring path);
    };


}
