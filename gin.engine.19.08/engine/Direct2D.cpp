#include "pch.h"
#include "Direct2D.h"
#include <d2d1_1.h>
#include <wrl/client.h>
#include <wincodec.h>



#define SAFE_RELEASE(x) { if(x) {x->Release(); x = nullptr;} }


namespace Graphics
{
	Direct2D::Direct2D(Direct3D* d3d)
	{
		try {
			init(d3d);
		}
		catch (bool)
		{
			shutdown();
			throw false;
		}
	}


	

	void Direct2D::init(Direct3D* d3d)
	{
		ID2D1Factory* pD2DFactory = nullptr;
		HRESULT hResult = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory);
		if (SUCCEEDED(hResult))
		{
			IDXGISurface* pBackBuffer = nullptr;

			d3d->pSwapChain->GetBuffer(0, __uuidof(IDXGISurface), (void**)&pBackBuffer);

			if (SUCCEEDED(hResult))
			{
				FLOAT dpiX = (FLOAT)GetDpiForWindow(GetDesktopWindow());
				FLOAT dpiY = dpiX;

				D2D1_RENDER_TARGET_PROPERTIES props =
					D2D1::RenderTargetProperties(
						D2D1_RENDER_TARGET_TYPE_DEFAULT,
						D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED),
						dpiX,
						dpiY
					);

				hResult = pD2DFactory->CreateDxgiSurfaceRenderTarget(
					pBackBuffer,
					&props,
					&pD2D1RenderTarget
				);

				pBackBuffer->Release();
			}
			pD2DFactory->Release();
		}

		if (FAILED(hResult))
			throw false;

		createDirectWriteFactory();
		

	}


	/*Image2D* Direct2D::createImage(wstring filename)
	{
		Image2D* image = new Image2D;
		CreateBitmapFromFile(filename.c_str(), &image->pBitmap);
		D2D1_SIZE_F size = image->pBitmap->GetSize();
		image->w = size.width;
		image->h = size.height;
		return image;
	}*/

	bool Direct2D::CreateBitmapFromFile(PCWSTR uri, ID2D1Bitmap** ppBitmap) {

		IWICImagingFactory* d2dWICFactory = NULL;
		IWICBitmapDecoder* d2dDecoder = NULL;
		IWICFormatConverter* d2dConverter = NULL;
		IWICBitmapFrameDecode* d2dBmpSrc = NULL;

		HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

		if (FAILED(hr)) return FALSE;

		hr = CoCreateInstance(
			CLSID_WICImagingFactory,
			NULL,
			CLSCTX_INPROC_SERVER,
			__uuidof(IWICImagingFactory),
			(void**)(&d2dWICFactory)
		);

		if (FAILED(hr)) return FALSE;

		hr = d2dWICFactory->CreateDecoderFromFilename(
			uri,
			NULL,
			GENERIC_READ,
			WICDecodeMetadataCacheOnLoad,
			&d2dDecoder
		);

		if (FAILED(hr)) return FALSE;

		hr = d2dWICFactory->CreateFormatConverter(&d2dConverter);

		if (FAILED(hr)) return FALSE;

		hr = d2dDecoder->GetFrame(0, &d2dBmpSrc);

		if (FAILED(hr)) return FALSE;

		hr = d2dConverter->Initialize(
			d2dBmpSrc,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL,
			0.f,
			WICBitmapPaletteTypeMedianCut
		);

		if (FAILED(hr)) return FALSE;

		hr = pD2D1RenderTarget->CreateBitmapFromWicBitmap(
			d2dConverter,
			NULL,
			ppBitmap
		);

		if (FAILED(hr)) return FALSE;


		if (d2dWICFactory) d2dWICFactory->Release();
		if (d2dDecoder) d2dDecoder->Release();
		if (d2dConverter) d2dConverter->Release();
		if (d2dBmpSrc) d2dBmpSrc->Release();

		CoUninitialize();

		return TRUE;
	}

	bool Direct2D::createSolidBrush(float r, float g, float b, float a, ID2D1SolidColorBrush** pSolidBrush)
	{
		HRESULT hResult = pD2D1RenderTarget->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF(r, g, b, a)),
			pSolidBrush
		);

		return SUCCEEDED(hResult);
	}
	/*
	Image2D* Direct2D::loadImage(std::wstring filename)
	{
		ID2D1Bitmap* pBitmap = nullptr;
		if (!BitmapLoader::CreateBitmapFromFile(filename, pD2D1RenderTarget, &pBitmap))
		{
			OutputDebugStringW(L"error loading bitmap");
		}

		return new Image2D(pBitmap);
	}

	bool Direct2D::createTextFormat(std::wstring fontname, int fontSize, IDWriteTextFormat** pFormat)
	{

		HRESULT hResult = m_pDWriteFactory->CreateTextFormat(
			fontname.c_str(),
			NULL,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			fontSize,
			L"", //locale
			pFormat
		);

		if (FAILED(hResult))
		{
			OutputDebugStringW(L"Direct2D::createTextFormat error");
			return false;
		}

		return true;
	}
	*/

	void Direct2D::shutdown()
	{
		SAFE_RELEASE(m_pDWriteFactory);
		SAFE_RELEASE(pD2D1RenderTarget);
	}

	Direct2D::~Direct2D()
	{
		shutdown();
	}

	bool Direct2D::createDirectWriteFactory()
	{
		{
			HRESULT hResult = DWriteCreateFactory(
				DWRITE_FACTORY_TYPE_SHARED,
				__uuidof(m_pDWriteFactory),
				reinterpret_cast<IUnknown**>(&m_pDWriteFactory)
			);

			if (SUCCEEDED(hResult))
				return true;

			return false;
		}



		/*
		void Direct2D::drawImage(Image2D* img)
		{
			pD2DRenderTarget->DrawBitmap(
				img->pBitmap,
				D2D1::RectF(img->x, img->y, img->x + img->w, img->y + img->h),
				1,
				D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,     //D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
				D2D1::RectF(0, 0, img->w, img->h)
			);
		}
		*/

	}

}