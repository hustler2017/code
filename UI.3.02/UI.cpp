#include "UI.h"

namespace UI
{

	UI::UI(Graphics::Direct2D* d2d, System::IInput* input)
	{
		m_input = input;
		m_d2d = d2d;

		m_cursor = new UICursor(d2d);
	}

	UI::~UI()
	{
		for (auto it = m_elements.begin(); it != m_elements.end(); it++)
			delete (*it);
	}

	IUICursor* UI::getCursor()
	{
		return m_cursor;
	}

	void UI::render()
	{
		m_d2d->pD2D1RenderTarget->BeginDraw();

		for (auto it = m_elements.begin(); it != m_elements.end(); it++)
		{
			(*it)->renderElement();
		}
		
		m_cursor->render();

		m_d2d->pD2D1RenderTarget->EndDraw();
	}

	bool UI::updateInput()
	{
		int x = m_input->getMouseX();
		int y = m_input->getMouseY();

		m_cursor->setPositionX(x);
		m_cursor->setPositionY(y);

		if (m_input->isMouseLeftDown()) {
			if (eventMouseDown(x, y))
			{
				return true;
			}
		}
			
		if (m_input->isMouseLeftUp()) {
			if(eventMouseUp(x, y))
			{
				return true;
			}
		}
			
		if (lastMouseX != x || lastMouseY != y) {
			lastMouseX = x;
			lastMouseY = y;

			if(eventMouseMove(x, y))
			{
				return true;
			}
		}
			
		return false;
	}

	bool UI::eventMouseClick(int x, int y)
	{
		for (auto it = m_elements.begin(); it != m_elements.end(); it++)
		{
			if ((*it)->contain(x, y)) 
				return (*it)->eventMouseClick(x, y);
		}

		return false;
	}

	bool UI::eventMouseMove(int x, int y)
	{
		for (auto it = m_elements.begin(); it != m_elements.end(); it++)
		{
			if ((*it)->contain(x, y)) 
				return (*it)->eventMouseMove(x, y);
		}

		return false;
	}

	bool UI::eventMouseDown(int x, int y)
	{
		for (auto it = m_elements.begin(); it != m_elements.end(); it++)
		{
			if ((*it)->contain(x, y)) 
				return (*it)->eventMouseDown(x, y);
		}
		return false;
	}

	bool UI::eventMouseUp(int x, int y)
	{
		for (auto it = m_elements.begin(); it != m_elements.end(); it++)
		{
			if ((*it)->contain(x, y)) 
				return (*it)->eventMouseUp(x, y);
		}
		return false;
	}

	bool UI::eventKeyDown(int key)
	{
		//if (m_focused) m_focused->eventKeyDown(key);
		return false;
	}

	bool UI::eventKeyUp(int key)
	{
		//if (m_focused) m_focused->eventKeyUp(key);
		return false;
	}


	void UI::addElement(UIElement* element)
	{
		m_elements.push_back(element);
	}
}