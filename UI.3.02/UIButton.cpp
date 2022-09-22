#include "UIButton.h"

namespace UI
{

	void UIButton::clearResources()
	{
		if (m_pTextFormat) m_pTextFormat->Release();
		if (m_pSolidBrush) m_pSolidBrush->Release();

		for (int i = 0; i < State::STATES_NUMBER; i++)
		{
			if (presets[i].gradientStopCollectionBackground)
				presets[i].gradientStopCollectionBackground->Release();
			if (presets[i].gradientStopCollectionBorder)
				presets[i].gradientStopCollectionBorder->Release();
		}
	}


	void UIButton::CreateGradientStopCollection(ID2D1GradientStopCollection** collection, D2D1_COLOR_F color1, D2D1_COLOR_F color2)
	{
		D2D1_GRADIENT_STOP gradientStops[2];

		gradientStops[0].color = color1;  ;
		gradientStops[0].position = 0.0f;
		gradientStops[1].color = color2; //D2D1::ColorF(0.47f, 0.47f, 0.47f, 1.0);
		gradientStops[1].position = 1.0f;

		HRESULT hResult = m_d2d->pD2D1RenderTarget->CreateGradientStopCollection(
			gradientStops,
			2,
			D2D1_GAMMA_2_2,
			D2D1_EXTEND_MODE_CLAMP,
			collection
		);

		if (FAILED(hResult)) throw false;
	}

	void UIButton::createResources()
	{
		CreateGradientStopCollection(
			&presets[BUTTON_NORMAL].gradientStopCollectionBackground,
			D2D1::ColorF( 54.0f / 255.0f, 54.0f / 255.0f, 54.0f / 255.0f, 1.0f),
			D2D1::ColorF(47.0f / 255.0f, 47.0f / 255.0f, 47.0f / 255.0f, 1.0)
		);

		CreateGradientStopCollection(
			&presets[BUTTON_NORMAL].gradientStopCollectionBorder,
			D2D1::ColorF(53.0f / 255.0f, 53.0f / 255.0f, 53.0f / 255.0f, 1.0f),
			D2D1::ColorF(22.0f / 255.0f, 22.0f / 255.0f, 22.0f / 255.0f, 1.0)
		);

		CreateGradientStopCollection(
			&presets[BUTTON_HOVERED].gradientStopCollectionBackground,
			D2D1::ColorF(85.0f / 255.0f, 85.0f / 255.0f, 85.0f / 255.0f, 1.0f),
			D2D1::ColorF(25.0f / 255.0f, 25.0f / 255.0f, 25.0f / 255.0f, 1.0)
		);

		CreateGradientStopCollection(
			&presets[BUTTON_HOVERED].gradientStopCollectionBorder,
			D2D1::ColorF(53.0f / 255.0f, 53.0f / 255.0f, 53.0f / 255.0f, 1.0f),
			D2D1::ColorF(22.0f / 255.0f, 22.0f / 255.0f, 22.0f / 255.0f, 1.0)
		);

		CreateGradientStopCollection(
			&presets[BUTTON_PRESSED].gradientStopCollectionBackground,
			D2D1::ColorF(3.0f / 255.0f, 3.0f / 255.0f, 3.0f / 255.0f, 1.0f),
			D2D1::ColorF(62.0f / 255.0f, 62.0f / 255.0f, 62.0f / 255.0f, 1.0)
		);

		CreateGradientStopCollection(
			&presets[BUTTON_PRESSED].gradientStopCollectionBorder,
			D2D1::ColorF(53.0f / 255.0f, 53.0f / 255.0f, 53.0f / 255.0f, 1.0f),
			D2D1::ColorF(22.0f / 255.0f, 22.0f / 255.0f, 22.0f / 255.0f, 1.0)
		);

		if (false == m_d2d->createSolidBrush(0.0f, 1.0f, 0.0f, 1.0f, &m_pSolidBrush)) 
			throw false;
		if(false == m_d2d->createTextFormat(L"Verdana", 12, &m_pTextFormat)) 
			throw false;

		m_pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT::DWRITE_TEXT_ALIGNMENT_CENTER);
		m_pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	}

	UIButton::UIButton(Graphics::Direct2D* d2d) : UIElement(d2d)
	{
		try {
			createResources();
		}
		catch (bool)
		{
			clearResources();
			throw false;
		}

		
	}

	UIButton::~UIButton()
	{
		clearResources();
	}

	void UIButton::setText(std::wstring text)
	{
		m_text = text;
	}

	void UIButton::render()
	{
		
		
		D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(
			D2D1::RectF(
				globalX(position.x),
				globalY(position.y),
				globalX(position.x) + position.width,
				globalY(position.y) + position.height
			),
			10.f,
			10.f
		);


		Preset* preset = nullptr;

		if (pushed) preset = &presets[BUTTON_PRESSED];
		else if (m_mouse_over) preset = &presets[BUTTON_HOVERED];
		else preset = &presets[BUTTON_NORMAL];

		ID2D1LinearGradientBrush* m_pBackgroundBrush = nullptr;
		ID2D1LinearGradientBrush* m_pBorderBrush = nullptr;

		HRESULT hResult = m_d2d->pD2D1RenderTarget->CreateLinearGradientBrush(
			D2D1::LinearGradientBrushProperties(
				D2D1::Point2F(0, rect.rect.top),
				D2D1::Point2F(0, rect.rect.bottom)),
			preset->gradientStopCollectionBackground,
			&m_pBackgroundBrush
		);

		if (SUCCEEDED(hResult))
		{
			m_d2d->pD2D1RenderTarget->FillRoundedRectangle(rect, m_pBackgroundBrush);
		}

		hResult = m_d2d->pD2D1RenderTarget->CreateLinearGradientBrush(
			D2D1::LinearGradientBrushProperties(
				D2D1::Point2F(0, rect.rect.top),
				D2D1::Point2F(0, rect.rect.bottom)),
			preset->gradientStopCollectionBorder,
			&m_pBorderBrush
		);

		if (SUCCEEDED(hResult))
		{
			m_d2d->pD2D1RenderTarget->DrawRoundedRectangle(rect, m_pBorderBrush, 2.0f);
		}
		/*
		m_d2d->pD2D1RenderTarget->DrawText(
			m_text.c_str(),
			m_text.length(),
			m_pTextFormat,
			rect,
			m_pSolidBrush
		);
		*/
		if (m_pBackgroundBrush) m_pBackgroundBrush->Release();
		if (m_pBorderBrush) m_pBorderBrush->Release();
	}


	bool UIButton::eventMouseDown(int x, int y)
	{
		OutputDebugStringA("eventMouseDown");
		
		pushed = true;
		
		if (m_onMouseDown) 
			return m_onMouseDown(x, y);

		return false;
	}

	bool UIButton::eventMouseUp(int x, int y)
	{
		OutputDebugStringA("eventMouseUp");
		
		pushed = false;

		if (m_onMouseUp)
			return m_onMouseUp(x, y);

		return false;
	}

	
}

