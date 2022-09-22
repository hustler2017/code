#pragma once

#include <list>
#include "Graphics\Graphics.h"
#include "System\SystemInterfaces.h"
#include "UI\UIInterfaces.h"
#include "UIElement.h"
#include "UICursor.h"

namespace UI {

	class UI : public UIInput, public UIInterface
	{
		std::list<UIElement*> m_elements;
		
		System::IInput* m_input = nullptr;
		UICursor* m_cursor = nullptr;

		int lastMouseX = 0;
		int lastMouseY = 0;

	protected:
		Graphics::Direct2D* m_d2d = nullptr;
	public:
		
		UI(Graphics::Direct2D* d2d, System::IInput* input);
		~UI();

		IUICursor* getCursor();

		void addElement(UIElement* element);
		void render();
		bool updateInput();
		bool eventMouseClick(int x, int y);
		bool eventMouseMove(int x, int y);
		bool eventMouseDown(int x, int y);
		bool eventMouseUp(int x, int y);
		bool eventKeyDown(int key);
		bool eventKeyUp(int key);
	};
}




