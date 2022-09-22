#include "Game.h"
#include <windowsx.h>
#include <d2d1.h>
#include <d2d1_1.h>
#include <math.h>
#include <dwrite.h>

ID2D1Factory* pD2DFactory = nullptr;
ID2D1HwndRenderTarget* pRenderTarget = nullptr;
ID2D1SolidColorBrush* pBrushBatUp = nullptr;
ID2D1SolidColorBrush* pBrushBatDown = nullptr;
ID2D1SolidColorBrush* pBrushGoal = nullptr;
ID2D1SolidColorBrush* pBrushBorders = nullptr;
ID2D1SolidColorBrush* pBrushPuck = nullptr;
IDWriteFactory* m_pDWriteFactory = nullptr;
IDWriteTextFormat* m_pTextFormat = nullptr;

const WCHAR msc_fontName[] = L"Verdana";
const FLOAT msc_fontSize = 14;



bool createRGBBrush(int r, int g, int b, ID2D1SolidColorBrush* &pBrush)
{
	if (r < 0 || r > 255) return false;
	if (g < 0 || g > 255) return false;
	if (b < 0 || b > 255) return false;


	HRESULT hr = pRenderTarget->CreateSolidColorBrush(
		D2D1::ColorF(
			static_cast<float>(r) / 255.0f, 
			static_cast<float>(g) / 255.0f, 
			static_cast<float>(b) / 255.0f, 
			1.0f
		),
		&pBrush
	);

	if (FAILED(hr))
		return false;

	return true;
}
bool initD2D(HWND hwnd)
{
	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED, 
		&pD2DFactory
	);

	if (FAILED(hr))
		return false;

	RECT rc;
	GetClientRect(hwnd, &rc);

	hr = pD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top)),
		&pRenderTarget
	);

	if (FAILED(hr)) 
		return false;
	
	if (!createRGBBrush(113,2,2, pBrushBatUp)) return false;
	if (!createRGBBrush(166, 20, 20, pBrushBatDown)) return false;
	if (!createRGBBrush(34, 34, 131, pBrushBorders)) return false;
	if (!createRGBBrush(255, 255, 0, pBrushPuck)) return false;
	if (!createRGBBrush(71, 8, 142, pBrushGoal)) return false;



	DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(m_pDWriteFactory),
		reinterpret_cast<IUnknown**>(&m_pDWriteFactory)
	);

	m_pDWriteFactory->CreateTextFormat(
		msc_fontName,
		NULL,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		msc_fontSize,
		L"", //locale
		&m_pTextFormat
	);


	return true;

}
void shutdownD2D()
{
	if (m_pDWriteFactory)
	{
		m_pDWriteFactory->Release();
		m_pDWriteFactory = nullptr;
	}

	if (pRenderTarget) {
		pRenderTarget->Release();
		pRenderTarget = nullptr;
	}

	if (pD2DFactory) {
		pD2DFactory->Release();
		pD2DFactory = nullptr;
	}

	if (pBrushBatUp) {
		pBrushBatUp->Release();
		pBrushBatUp = nullptr;
	}
	if (pBrushBatDown) {
		pBrushBatDown->Release();
		pBrushBatDown = nullptr;
	}
	if (pBrushGoal) {
		pBrushGoal->Release();
		pBrushGoal = nullptr;
	}
	if (pBrushPuck) {
		pBrushPuck->Release();
		pBrushPuck = nullptr;
	}
	if (pBrushBorders) {
		pBrushBorders->Release();
		pBrushBorders = nullptr;
	}



}

Game::Game()
{

}

Game::~Game()
{

}

void Game::running()
{
	field.update();
}

void Game::starting()
{
	if (startCounter < 0)
	{
		state = RUNNING;
		return;
	}
}

void Game::ending()
{
	
}

void Game::update()
{
	switch (state)
	{
	case STARTING:
		starting();
		break;
	case RUNNING:
		running();
		break;
	case ENDING:
		ending();
		break;
	}

}

void Game::render()
{
	if (pRenderTarget) {
		pRenderTarget->BeginDraw();
		pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
		
		
		pRenderTarget->SetTransform(
			//D2D1::Matrix3x2F::Scale(D2D1::Size(1.f, -1.f), D2D1::Point2F(0, 0)) *
			D2D1::Matrix3x2F::Translation(1920.0f / 2.0f, 1080.f/2.f)
		);

		pRenderTarget->DrawLine(D2D1::Point2F(0.0f, 0.0f), D2D1::Point2F(600.0f, 0.0f), pBrushGoal, 1.0f);
		pRenderTarget->DrawLine(D2D1::Point2F(0.0f, 0.0f), D2D1::Point2F(0.0f, 600.0f), pBrushGoal, 1.0f);
		

		field.draw();
		
		pRenderTarget->EndDraw();
	}
}


void Game::shutdown()
{
	shutdownD2D();
}

bool Game::initGame()
{
	return true;
}

bool Game::init(HWND hwnd)
{
	if (initD2D(hwnd))
		if (initGame())
			return true;

	shutdownD2D();	
	return false;
}




void Game::updateState(int dx, int dy)
{
	field.updateState(dx,dy);
}