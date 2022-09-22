#pragma once
#include "UIElement.h"

namespace UI
{
	class UISlider : public UIElement
	{

		struct runningLine
		{
			int y;
			int x0;
			int x1;

			int x_left;
			int x_top;
			int x_right;
			int x_bottom;

			
		};

		struct slider
		{
			int x_center;
			int y_center;
			int x_left;
			int x_top;
			int x_right;
			int x_bottom;
		};


		int runningLineY;
		int runningLineX0;
		int runningLineX1;
		int runningLineLength;

		int lineBorder = 1;

		int sliderWidth;
		int sliderHeight;

		int borderSpace;

		int sliderCenterX;
		int sliderCenterY;
		bool captured = false;
		int captured_x;
		int captured_y;

		float minValue = 0.0f;
		float maxValue = 1.0f;
		float sliderPos = 0.0f;

		float m_value = 0.0f;

		
		UIElement slider = nullptr;
		ID2D1SolidColorBrush* m_plineBrush = nullptr;
		ID2D1GradientStopCollection* m_backgroundGradientStopCollection = nullptr;
		ID2D1GradientStopCollection* m_borderGradientStopCollection = nullptr;
		void createResources();
		void clearResources();
		void calculatePositions();

		void setValue(float value);
		

	public:
		float getValue();
		UISlider(Graphics::Direct2D* d2d);
		~UISlider();
		void render();
		void setPosition(int x, int y);
		void setWidth(int w);
		void setHeight(int h);

		bool eventMouseDown(int x, int y);
		bool eventMouseUp(int x, int y);
		bool eventMouseMove(int x, int y);
		bool eventMouseLeave(int x, int y);
	};
}


