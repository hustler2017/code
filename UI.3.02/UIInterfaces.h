#pragma once

#include "Graphics\GraphicsInterfaces.h"

namespace UI
{
	class IUICursor
	{
	public:
		virtual int getPositionX() = 0;
		virtual void setPositionX(int x) = 0;
		virtual int getPositionY() = 0;
		virtual void setPositionY(int y) = 0;
		virtual bool setImage(Graphics::IImage2D* image) = 0;
	};


	class UIInterface
	{
	public:
		virtual IUICursor* getCursor() = 0;
		virtual void render() = 0;
		virtual bool updateInput() = 0;

	};
}