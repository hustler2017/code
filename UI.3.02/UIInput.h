#pragma once
namespace UI
{
	class UIInput
	{
	public:
		virtual bool eventMouseClick(int x, int y) { return false; }
		virtual bool eventMouseUp(int x, int y) { return false; }
		virtual bool eventMouseDown(int x, int y) { return false; }
		virtual bool eventMouseEnter(int x, int y) { return false; };
		virtual bool eventMouseLeave(int x, int y) { return false; }
		virtual bool eventMouseMove(int x, int y) { return false; }
		virtual bool eventKeyDown(int key) { return false; }
		virtual bool eventKeyUp(int key) { return false; }
	};
}
