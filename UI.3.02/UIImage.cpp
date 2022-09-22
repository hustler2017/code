#include "UIImage.h"

namespace UI
{

	UIImage::UIImage(Graphics::Direct2D* d2d) : UIElement(d2d) {

		try {
			createResources();
		}
		catch (bool)
		{
			deleteResources();
			throw false;
		}
	}
	UIImage::~UIImage()
	{
		deleteResources();
	}

	void UIImage::createResources()
	{
		

		HRESULT hResult = m_d2d->pD2D1RenderTarget->CreateSolidColorBrush(D2D1::ColorF(0.1f, 0.1f, 0.1f, 1.0f), &m_pBorderBrush);
		if (FAILED(hResult))
		{
			throw false;
		}
	}

	void UIImage::deleteResources()
	{
		if (m_pBorderBrush) m_pBorderBrush->Release();
	}

	void UIImage::setImage(Graphics::Image2D* pImage)
	{
		m_pImage = pImage;
	}

	void UIImage::render()
	{
		int border = 2;

		D2D1_RECT_F borderRect = D2D1::RectF(
			globalX(position.x),
			globalY(position.y),
			globalX(position.x + position.width),
			globalY(position.y + position.height)
		);

		D2D1_RECT_F imageRect = D2D1::RectF(
			globalX(position.x + border),
			globalY(position.y + border),
			globalX(position.x + position.width - border),
			globalY(position.y + position.height - border)
		);

		m_d2d->pD2D1RenderTarget->DrawBitmap(
			m_pImage->getBitmap(),
			imageRect,
			1,
			D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,     
			D2D1::RectF(0, 0, m_pImage->getWidth(), m_pImage->getHeight())
		);

		m_d2d->pD2D1RenderTarget->DrawRectangle(borderRect, m_pBorderBrush, border);

	}
}
