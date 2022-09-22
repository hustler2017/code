#pragma once
#include "pch.h"
#include "Direct3D.h"
#include <d2d1.h>
#include <d2d1_1.h> 
#include <string>
#include <dwrite.h>


namespace Graphics 
{ 
	class Direct2D
	{
	private:
        IDWriteFactory* m_pDWriteFactory = nullptr;
		

		void init(Direct3D*);
		void shutdown();
		bool createDirectWriteFactory();
		

	public:
		ID2D1RenderTarget* pD2D1RenderTarget = nullptr;
		//ID2D1SolidColorBrush* pBrush = nullptr;


		Direct2D(Direct3D*);
		~Direct2D();
		
		bool createTextFormat(std::wstring fontname, int fontSize, IDWriteTextFormat** pFormat);
		bool createSolidBrush(float r, float g, float b, float a, ID2D1SolidColorBrush** pSolidBrush);
		bool CreateBitmapFromFile(PCWSTR uri, ID2D1Bitmap** ppBitmap);

		//void drawImage(Image2D* img);
		//Image2D* createImage(wstring filename);
	};

}

