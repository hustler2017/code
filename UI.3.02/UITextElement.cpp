#include "UITextElement.h"



namespace UI
{
	UITextElement::UITextElement(Graphics::Direct2D* d2d) : UIElement(d2d)
	{
		d2d->createTextFormat(L"Verdana", 10, &m_pTextFormat);
		m_pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		m_pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

		d2d->createSolidBrush(0.9f, 0.4f, 0.9f, 1.0f, &m_pSolidBrush);
	}

	UITextElement::~UITextElement()
	{
		if (m_pTextFormat) m_pTextFormat->Release();
		if (m_pSolidBrush) m_pSolidBrush->Release();
	}

	void UITextElement::setText(std::wstring t) 
	{ 
		m_text = t; 
	}

	std::wstring UITextElement::getText() 
	{ 
		return m_text; 
	}

	void UITextElement::render()
	{
		m_d2d->pD2D1RenderTarget->DrawText(
			m_text.c_str(),
			m_text.length(),
			m_pTextFormat,
			D2D1::RectF(globalX(position.x), globalY(position.y), position.width, position.height),
			m_pSolidBrush
		);

	}
}