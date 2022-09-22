#pragma once
#include "UIInput.h"
#include <functional>

namespace UI
{
	class UIInputEvent : public UIInput
	{
	protected:
		std::function<bool(int x, int y)> m_onMouseClick = nullptr;
		std::function<bool(int x, int y)> m_onMouseUp = nullptr;
		std::function<bool(int x, int y)> m_onMouseDown = nullptr;
		std::function<bool(int x, int y)> m_onMouseEnter = nullptr;
		std::function<bool(int x, int y)> m_onMouseLeave = nullptr;
		std::function<bool(int x, int y)> m_onMouseMove = nullptr;
		std::function<bool(int key)> m_onKeyDown = nullptr;
		std::function<bool(int key)> m_onKeyUp = nullptr;

	public:

		void onMouseClick(std::function<bool(int x, int y)> handler) { m_onMouseClick = handler; }
		void onMouseUp(std::function<bool(int x, int y)> handler) { m_onMouseUp = handler; }
		void onMouseDown(std::function<bool(int x, int y)> handler) { m_onMouseDown = handler; }
		void onMouseEnter(std::function<bool(int x, int y)> handler) { m_onMouseEnter = handler; }
		void onMouseLeave(std::function<bool(int x, int y)> handler) { m_onMouseLeave = handler; }
		void onMouseMove(std::function<bool(int x, int y)> handler) { m_onMouseMove = handler; }
		void onKeyDown(std::function<bool(int key)> handler) { m_onKeyDown = handler; }
		void onKeyUp(std::function<bool(int key)> handler) { m_onKeyUp = handler; }
	};
}
