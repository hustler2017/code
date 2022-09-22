#pragma once

#include "Graphics\Direct2D.h"
#include "UI\UIInterfaces.h"
#include "Graphics\GraphicsInterfaces.h"


namespace UI {

	class UICursor : public IUICursor
	{
		Graphics::Direct2D* m_d2d;
		ID2D1Bitmap* m_image = nullptr;

	public: 
		struct Position
		{
			int x;
			int y;
			int width;
			int height;
		};

		Position position;

		UICursor(Graphics::Direct2D* d2d) : m_d2d(d2d) {};
		~UICursor() {};
		void render();
		int getPositionX();
		void setPositionX(int x);
		int getPositionY();
		void setPositionY(int y);
		bool setImage(Graphics::IImage2D* image);
	};

}

