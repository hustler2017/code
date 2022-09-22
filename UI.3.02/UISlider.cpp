#include "UISlider.h"


namespace UI
{
	UISlider::UISlider(Graphics::Direct2D* d2d) : UIElement(d2d)
	{
		position.x = 0;
		position.y = 0;
		position.width = 100;
		position.height = 20;

		m_value = minValue;

		sliderWidth = 20;
		sliderHeight = 20;

		calculatePositions();

		try {
			createResources();
		}
		catch (bool)
		{
			clearResources();
			throw false;
		}

	}

	bool UISlider::eventMouseLeave(int x, int y)
	{
		captured = false;
		return true;
	}

	void UISlider::createResources()
	{
		if (false == m_d2d->createSolidBrush(63.0f / 255.0f, 63.0f / 255.0f, 63.0f / 255.0f, 1.0f, &m_plineBrush)){
			throw false;
		}

		HRESULT hResult;
		D2D1_GRADIENT_STOP gradientStops[2];

		gradientStops[0].color = D2D1::ColorF(54.0f / 255.0f, 54.0f / 255.0f, 54.0f / 255.0f, 1.0f);
		gradientStops[0].position = 0.0f;
		gradientStops[1].color = D2D1::ColorF(47.0f / 255.0f, 47.0f / 255.0f, 47.0f / 255.0f, 1.0);
		gradientStops[1].position = 1.0f;

		hResult = m_d2d->pD2D1RenderTarget->CreateGradientStopCollection(
			gradientStops,
			2,
			D2D1_GAMMA_2_2,
			D2D1_EXTEND_MODE_CLAMP,
			&m_backgroundGradientStopCollection
		);

		if (FAILED(hResult)) throw false;

		gradientStops[0].color = D2D1::ColorF(53.0f / 255.0f, 53.0f / 255.0f, 53.0f / 255.0f, 1.0f);
		gradientStops[0].position = 0.0f;
		gradientStops[1].color = D2D1::ColorF(22.0f / 255.0f, 22.0f / 255.0f, 22.0f / 255.0f, 1.0);
		gradientStops[1].position = 1.0f;

		hResult = m_d2d->pD2D1RenderTarget->CreateGradientStopCollection(
			gradientStops,
			2,
			D2D1_GAMMA_2_2,
			D2D1_EXTEND_MODE_CLAMP,
			&m_borderGradientStopCollection
		);

		if (FAILED(hResult)) throw false;

	}




	bool UISlider::eventMouseMove(int x, int y)
	{
		int local_x = localX(x);
		int local_y = localY(y);

		if (captured)
		{
			sliderCenterX = local_x + captured_x ;
			if (sliderCenterX < runningLineX0) sliderCenterX = runningLineX0;
			if (sliderCenterX > runningLineX1) sliderCenterX = runningLineX1;

			sliderPos = (sliderCenterX - runningLineX0) / float(runningLineLength);
			m_value = minValue + sliderPos * (maxValue - minValue);

			if (m_onMouseMove)
			{
				m_onMouseMove(x, y);
			}
		}

		return true;
	}




	void UISlider::setPosition(int x, int y)
	{
		UIElement::setPosition(x, y);
		calculatePositions();
	}

	void UISlider::setWidth(int w)
	{
		UIElement::setWidth(w);
		calculatePositions();
	}


	void UISlider::setHeight(int h)
	{
		UIElement::setHeight(h);
		calculatePositions();
	}



	void UISlider::setValue(float value) {
		
		if (value > maxValue)
		{
			m_value = maxValue;
		}

		if (value < minValue)
		{
			m_value = minValue;
		}

		sliderPos = (minValue + m_value) / (maxValue - minValue);
	}

	float UISlider::getValue() 
	{
		return m_value; 
	}

	void UISlider::calculatePositions()
	{
		runningLineY = position.height / 2;
		runningLineLength = position.width - sliderWidth;
		if (runningLineLength < 0) runningLineLength = 0;
		borderSpace = (position.width - runningLineLength) / 2;
		runningLineX0 = borderSpace;
		runningLineX1 = runningLineX0 + runningLineLength;
		sliderCenterY = runningLineY;
		sliderPos = (m_value - minValue) / (maxValue - minValue);
		sliderCenterX = runningLineX0 + sliderPos * (runningLineLength);
	}

	void UISlider::clearResources()
	{
		if (m_plineBrush) m_plineBrush->Release();
		if (m_backgroundGradientStopCollection) m_backgroundGradientStopCollection->Release();
		if (m_borderGradientStopCollection) m_borderGradientStopCollection->Release();
	}
	
	void UISlider::render()
	{

		/*
		D2D1_RECT_F elementRect = D2D1::RectF(
			globalX(position.x),
			globalY(position.y),
			globalX(position.x + position.width),
			globalY(position.y + position.height)
		);
		*/
		
		D2D1_RECT_F lineRect = D2D1::RectF(
			globalX(position.x + runningLineX0) - lineBorder,
			globalY(position.y + runningLineY) - lineBorder,
			globalX(position.x + runningLineX1) + lineBorder,
			globalY(position.y + runningLineY) + lineBorder
		);

		D2D1_ROUNDED_RECT sliderRect = D2D1::RoundedRect(
			D2D1::RectF(
				globalX(position.x + sliderCenterX) - sliderWidth / 2.0f,
				globalY(position.y + sliderCenterY) - sliderHeight / 2.0f,
				globalX(position.x + sliderCenterX) + sliderWidth / 2.0f,
				globalY(position.y + sliderCenterY) + sliderHeight / 2.0f
			),
			sliderWidth / 2.0f,
			sliderHeight / 2.0f
		);

		//m_d2d->pD2D1RenderTarget->DrawRectangle(elementRect, m_plineBrush, 1.0f);
		m_d2d->pD2D1RenderTarget->DrawRectangle(lineRect, m_plineBrush, lineBorder);

		
		ID2D1LinearGradientBrush* sliderBackgroundBrush = nullptr;

		HRESULT hResult = m_d2d->pD2D1RenderTarget->CreateLinearGradientBrush(
			D2D1::LinearGradientBrushProperties(
				D2D1::Point2F(0, sliderRect.rect.top),
				D2D1::Point2F(0, sliderRect.rect.bottom)),
			m_backgroundGradientStopCollection,
			&sliderBackgroundBrush
		);

		if (SUCCEEDED(hResult))
		{
			m_d2d->pD2D1RenderTarget->FillRoundedRectangle(sliderRect, sliderBackgroundBrush);
		}
		
		ID2D1LinearGradientBrush* sliderBorderBrush = nullptr;

		hResult = m_d2d->pD2D1RenderTarget->CreateLinearGradientBrush(
			D2D1::LinearGradientBrushProperties(
				D2D1::Point2F(0, sliderRect.rect.top),
				D2D1::Point2F(0, sliderRect.rect.bottom)),
			m_borderGradientStopCollection,
			&sliderBorderBrush
		);

		if (SUCCEEDED(hResult))
		{
			m_d2d->pD2D1RenderTarget->DrawRoundedRectangle(sliderRect, sliderBorderBrush, lineBorder);
		}

		if (sliderBorderBrush) sliderBorderBrush->Release();
		if (sliderBackgroundBrush) sliderBackgroundBrush->Release(); 
		
	}


	bool UISlider::eventMouseDown(int x, int y)
	{
		int local_x = localX(x);
		int local_y = localY(y);

		int slider_left = sliderCenterX - sliderWidth / 2;
		int slider_top = sliderCenterY - sliderHeight / 2;

		int slider_right = sliderCenterX + sliderWidth / 2;
		int slider_bottom = sliderCenterY + sliderHeight / 2;

		if (local_x > slider_left && local_x < slider_right && local_y < slider_bottom && local_y > slider_top)
		{
			captured = true;
			captured_x = sliderCenterX - local_x;
		}

		return true;
	}

	bool UISlider::eventMouseUp(int x, int y)
	{
		int local_x = localX(x);
		int local_y = localY(y);

		captured = false;

		return true;
	}
	


	UISlider::~UISlider()
	{
		clearResources();
	}
}