#include "UICursor.h"
#include "Graphics\Image2D.h"

namespace UI
{

	int UICursor::getPositionX()
	{
		return position.x;
	}

	void UICursor::setPositionX(int x)
	{
		position.x = x;
	}

	int UICursor::getPositionY()
	{
		return position.y;
	}
	void UICursor::setPositionY(int y)
	{
		position.y = y;
	}

	bool UICursor::setImage(Graphics::IImage2D* image)
	{
		Graphics::Image2D* img = dynamic_cast<Graphics::Image2D*>(image);
		if (img)
		{
			m_image = img->getBitmap();
			position.width = img->getWidth();
			position.height = img->getHeight();
			return true;
		}

		return false;
	}

	void UICursor::render()
	{
		m_d2d->pD2D1RenderTarget->DrawBitmap(
			m_image,
			D2D1::RectF(position.x, position.y, position.x + position.width, position.y + position.height),
			1,
			D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,     //D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
			D2D1::RectF(0, 0, position.width, position.height)
		);
	}
}
