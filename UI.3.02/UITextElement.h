#pragma once
#include "UIElement.h"
#include <string>
#include <dwrite.h>

namespace UI
{
	class UITextElement : public UIElement
	{
		std::wstring m_text;
		IDWriteTextFormat* m_pTextFormat = nullptr;
		ID2D1SolidColorBrush* m_pSolidBrush = nullptr;
	public:
		UITextElement(Graphics::Direct2D* d2d);
		~UITextElement();
		void setText(std::wstring text);
		std::wstring getText();
		void render();
	};
}
