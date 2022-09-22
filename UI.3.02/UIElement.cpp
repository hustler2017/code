#include "UIElement.h"

namespace UI
{

	UIElement::UIElement(Graphics::Direct2D* d2d)
	{
		m_d2d = d2d;
		position.x = 0;
		position.y = 0;
		position.height = 100;
		position.width = 100;

	}

	UIElement::~UIElement()
	{
		for (auto it = m_children.begin(); it != m_children.end(); it++)
			delete (*it);

		m_children.clear();
	}

	void UIElement::setPosition(int x, int y)
	{
		position.x = x;
		position.y = y;
	}

	void UIElement::setWidth(int w)
	{
		position.width = w;
	}


	void UIElement::setHeight(int h)
	{
		position.height = h;
	}

	void UIElement::renderChildren()
	{
		for (auto it = m_children.begin(); it != m_children.end(); it++)
			(*it)->renderElement();
	}

	void UIElement::renderElement()
	{
		D2D1_RECT_F rect = { globalX(position.x) , globalY(position.y) , globalX(position.x) + position.width, globalY(position.y) + position.height };
		
		m_d2d->pD2D1RenderTarget->PushAxisAlignedClip(rect, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);

		render();
		
		renderChildren();

		m_d2d->pD2D1RenderTarget->PopAxisAlignedClip();
	}

	void UIElement::addChild(UIElement* element)
	{
		element->m_parent = this;
		m_children.push_back(element);
	}

	bool UIElement::contain(int _x, int _y)
	{
		return _x > position.x && _y > position.y && _x < (position.x + position.width) && _y < (position.y + position.height);
	}


	bool UIElement::eventMouseClick(int x, int y)
	{

		int local_x = localX(x);
		int local_y = localY(y);

		UIElement* element;
		for (auto it = m_children.begin(); it != m_children.end(); it++)
		{
			element = (*it);
			if (element->contain(local_x, local_y)) {
				return element->eventMouseClick(local_x, local_y);
			}
		}

		return false;
	}

	bool UIElement::eventMouseEnter(int x, int y)
	{
		m_mouse_over = true;

		if (m_onMouseEnter)
			m_onMouseEnter(x, y);

		return false;
	}

	bool UIElement::eventMouseLeave(int x, int y)
	{
		m_mouse_over = false;

		if (m_onMouseLeave)
			m_onMouseLeave(x, y);

		return false;
	}

	bool UIElement::getMouseOver()
	{
		return m_mouse_over;
	}

	bool UIElement::eventMouseMove(int x, int y)
	{
		int local_x = localX(x);
		int local_y = localY(y);

		UIElement* element;
		for (auto it = m_children.begin(); it != m_children.end(); it++)
		{
			element = (*it);
			if (element->contain(local_x, local_y)) {
				if(element->getMouseOver() == false)
					element->eventMouseEnter(local_x, local_y);

				return element->eventMouseMove(local_x, local_y);
			}
			else
			{
				if (element->getMouseOver() == true)
					element->eventMouseLeave(local_x, local_y);
			}
		}

		return false;
	}

	bool UIElement::eventMouseDown(int x, int y)
	{
		int local_x = localX(x);
		int local_y = localY(y);

		UIElement* element;
		for (auto it = m_children.begin(); it != m_children.end(); it++)
		{
			element = (*it);
			if (element->contain(local_x, local_y)) {
				return element->eventMouseDown(local_x, local_y);
			}
		}

		return false;
	}

	bool UIElement::eventMouseUp(int x, int y)
	{
		int local_x = localX(x);
		int local_y = localY(y);

		UIElement* element;
		for (auto it = m_children.begin(); it != m_children.end(); it++)
		{
			element = (*it);
			if (element->contain(local_x, local_y)) {
				return element->eventMouseUp(local_x, local_y);
			}
		}

		return false;
	}

	int UIElement::globalX(int x)
	{
		UIElement* t = this;
		while (t = t->m_parent)
			x += t->position.x;

		return x;
	}

	int UIElement::globalY(int y)
	{
		UIElement* t = this;
		while (t = t->m_parent)
			y += t->position.y;

		return y;
	}

	int UIElement::localX(int x)
	{
		return x - position.x;
	}

	int UIElement::localY(int y)
	{
		return y - position.y;
	}

}
