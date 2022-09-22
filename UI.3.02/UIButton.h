#pragma once
#include "UIElement.h"
#include <string>


namespace UI
{
	/*
	градиент фона, 
	градиент границы
	
	*/



	class UIButton : public UIElement
	{
	public:
		
	private:
		IDWriteTextFormat* m_pTextFormat = nullptr; 
		ID2D1SolidColorBrush* m_pSolidBrush = nullptr;
		
		struct Preset
		{
			ID2D1GradientStopCollection* gradientStopCollectionBackground = nullptr;
			ID2D1GradientStopCollection* gradientStopCollectionBorder = nullptr;
		};


		enum State
		{
			BUTTON_NORMAL,
			BUTTON_HOVERED,
			BUTTON_PRESSED,
			STATES_NUMBER
		};

		Preset presets[STATES_NUMBER];
		
		std::wstring m_text;

		bool pushed = false;

		void createResources();
		void clearResources();
		void CreateGradientStopCollection(ID2D1GradientStopCollection** collection, D2D1_COLOR_F color1, D2D1_COLOR_F color2);

	public:
		
		UIButton(Graphics::Direct2D* d2d);
		~UIButton();
		void render();
		void setText(std::wstring text);
		
		bool eventMouseDown(int x, int y);
		bool eventMouseUp(int x, int y);
	};


}
