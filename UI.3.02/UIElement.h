#pragma once

#include <list>
#include "UIInputEvent.h"
#include "Graphics\Graphics.h"

namespace UI
{
	class UIElement : public UIInputEvent
	{
	public:
		struct Position {
			int x;
			int y;
			int width;
			int height;
		};
	protected:
		
		int localX(int x);
		int localY(int y);
		int globalX(int y);
		int globalY(int y);

		bool m_mouse_over = false;

		UIElement* m_parent = nullptr;
		Graphics::Direct2D* m_d2d = nullptr;
		Position position;

	private:
		std::list<UIElement*> m_children;
	public:
		UIElement(Graphics::Direct2D* d2d);
		bool contain(int x, int y);
		virtual ~UIElement();
		void addChild(UIElement* element);
		void renderChildren();
		void renderElement();
		virtual void render() {}
		void setPosition(int x, int y);
		void setWidth(int w);
		void setHeight(int h);
		bool getMouseOver();

		bool eventMouseClick(int x, int y);
		bool eventMouseUp(int x, int y);
		bool eventMouseDown(int x, int y);
		bool eventMouseEnter(int x, int y);
		bool eventMouseLeave(int x, int y);
		bool eventMouseMove(int x, int y);
	};
}


