#include "pch.h"
#include "Direct3D.h"

#define SAFE_RELEASE(x) { if(x) x->Release(); x = nullptr; }

namespace Graphics
{
	Direct3D::Direct3D(HWND _hWnd)
	{
		hWnd = _hWnd;

		RECT rect;
		GetClientRect(hWnd, &rect);

		client_height = rect.bottom - rect.top;
		client_width = rect.right - rect.left;

		try {
			init();
		}
		catch (bool)
		{
			shutdown();
			throw false;
		}
	}

	void Direct3D::init()
	{
		createDevice();
		createSwapChain();
		createRenderTarget();
		createDepthBuffer();
		createBlendState();
		createRasterizerState();
		createSamplers();
		setup();

	}


	Direct3D::~Direct3D()
	{
		clearResources();
		shutdown();
	}

	void Direct3D::createDevice()
	{

		D3D_FEATURE_LEVEL featureLevel;

		HRESULT result = D3D11CreateDevice(
			0,
			D3D_DRIVER_TYPE_HARDWARE,
			NULL,
			D3D11_CREATE_DEVICE_DEBUG | D3D11_CREATE_DEVICE_SINGLETHREADED | D3D11_CREATE_DEVICE_BGRA_SUPPORT,
			0, 0,
			D3D11_SDK_VERSION,
			&pDevice,
			&featureLevel,
			&pContext
		);

		if (FAILED(result))
		{
			throw false;
		}
	}

	void Direct3D::clearResources()
	{
		for (const auto& tx : m_textures)
		{
			tx.second->Release();
		}

		m_textures.clear();
	}

	void Direct3D::createSwapChain()
	{
		DXGI_SWAP_CHAIN_DESC desc;
		desc.BufferDesc.Width = client_width;
		desc.BufferDesc.Height = client_height;
		desc.BufferDesc.RefreshRate.Denominator = 1;
		desc.BufferDesc.RefreshRate.Numerator = 60;
		desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		desc.SampleDesc.Count = 1;
		desc.SampleDesc.Quality = 0;
		desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		desc.BufferCount = 1;
		desc.OutputWindow = hWnd;
		desc.Windowed = true;
		desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		desc.Flags = 0;

		IDXGIDevice* dxgiDevice = 0;
		HRESULT hResult = pDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice);
		if (SUCCEEDED(hResult)) {

			IDXGIAdapter* dxgiAdapter = 0;
			hResult = dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&dxgiAdapter);
			if (SUCCEEDED(hResult)) {

				IDXGIFactory* dxgiFactory = 0;
				hResult = dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&dxgiFactory);
				if (SUCCEEDED(hResult)) {

					hResult = dxgiFactory->CreateSwapChain(pDevice, &desc, &pSwapChain);
					dxgiFactory->Release();
				}
				dxgiAdapter->Release();
			}
			dxgiDevice->Release();
		}

		if (FAILED(hResult))
			throw false;
	}

	void Direct3D::createRenderTarget()
	{
		ID3D11Texture2D* backBuffer = nullptr;

		HRESULT hResult = pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer));
		if (SUCCEEDED(hResult))
		{
			hResult = pDevice->CreateRenderTargetView(backBuffer, 0, &pRenderTarget);
			backBuffer->Release();
		}

		if (FAILED(hResult))
			throw false;
	}


	void Direct3D::createSamplers()
	{
		D3D11_SAMPLER_DESC sampDesc;
		ZeroMemory(&sampDesc, sizeof(sampDesc));
		sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
		sampDesc.MinLOD = 0;
		sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

		HRESULT hResult = pDevice->CreateSamplerState(&sampDesc, &pSamplerLinear);
		if (FAILED(hResult))
			throw false;
	}

	void Direct3D::turnWireMode(bool on)
	{
		if (on) {
			pContext->RSSetState(pWiresRasterizerState);
			
		}
		else {
			pContext->RSSetState(pNormalRasterizerState);
		}
	}

	void Direct3D::turnZBuffer(bool on)
	{
		if (on) {
			pContext->OMSetDepthStencilState(pStateNormal, 1);
		}
		else {
			pContext->OMSetDepthStencilState(pStateZBufferOff, 1);
		}
	}

	void Direct3D::setup()
	{
		D3D11_VIEWPORT vp;
		vp.TopLeftX = 0.0f;
		vp.TopLeftY = 0.0f;
		vp.Width = static_cast<float>(client_width);
		vp.Height = static_cast<float>(client_height);
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;

		

		pContext->RSSetViewports(1, &vp);
		pContext->PSSetSamplers(0, 1, &pSamplerLinear);
		pContext->OMSetRenderTargets(1, &pRenderTarget, pDepthView);
		pContext->OMSetBlendState(g_pBlendStateBlend, nullptr, 0xFFFFFFFFu);
		pContext->OMSetDepthStencilState(pStateNormal, 1);
		pContext->RSSetState(pNormalRasterizerState);
	}



	void Direct3D::createDepthBuffer()
	{
		D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
		ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

		// Настраиваем описание состояния трафарета.
		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

		depthStencilDesc.StencilEnable = true;
		depthStencilDesc.StencilReadMask = 0xFF;
		depthStencilDesc.StencilWriteMask = 0xFF;

		// Операции с трафаретом, если пиксель направлен вперед.
		depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// Операции с трафаретом, если пиксель направлен назад.
		depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// Создаем состояние трафарета глубины.
		HRESULT hResult = pDevice->CreateDepthStencilState(&depthStencilDesc, &pStateNormal);
		if (FAILED(hResult))
			throw false;



		D3D11_DEPTH_STENCIL_DESC depthDisabledStencilDesc;
		// Clear the second depth stencil state before setting the parameters.
		ZeroMemory(&depthDisabledStencilDesc, sizeof(depthDisabledStencilDesc));

		// Now create a second depth stencil state which turns off the Z buffer for 2D rendering.  The only difference is 
		// that DepthEnable is set to false, all other parameters are the same as the other depth stencil state.
		depthDisabledStencilDesc.DepthEnable = false;
		depthDisabledStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthDisabledStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;
		depthDisabledStencilDesc.StencilEnable = true;
		depthDisabledStencilDesc.StencilReadMask = 0xFF;
		depthDisabledStencilDesc.StencilWriteMask = 0xFF;
		depthDisabledStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthDisabledStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		depthDisabledStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthDisabledStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		depthDisabledStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthDisabledStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		depthDisabledStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthDisabledStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// Create the state using the device.
		hResult = pDevice->CreateDepthStencilState(&depthDisabledStencilDesc, &pStateZBufferOff);
		if (FAILED(hResult))
		{
			throw false;
		}


		D3D11_TEXTURE2D_DESC desc;
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.Width = client_width;
		desc.Height = client_height;
		desc.MipLevels = 1;
		desc.ArraySize = 1;
		desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		desc.SampleDesc.Count = 1;
		desc.SampleDesc.Quality = 0;
		desc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		desc.CPUAccessFlags = 0;
		desc.MiscFlags = 0;

		ID3D11Texture2D* pDepthBuffer = nullptr;

		bool succeeded = false;

		if (SUCCEEDED(pDevice->CreateTexture2D(&desc, 0, &pDepthBuffer)))
		{
			if (SUCCEEDED(pDevice->CreateDepthStencilView(pDepthBuffer, 0, &pDepthView)))
				succeeded = true;

			pDepthBuffer->Release();
		}

		if (!succeeded) throw false;
	}


	void Direct3D::createRasterizerState()
	{
		HRESULT hResult;
		{
			D3D11_RASTERIZER_DESC desc;
			ZeroMemory(&desc, sizeof(D3D11_RASTERIZER_DESC));
			desc.FillMode = D3D11_FILL_WIREFRAME;
			desc.CullMode = D3D11_CULL_BACK;
			hResult = pDevice->CreateRasterizerState(&desc, &pWiresRasterizerState);
			if (FAILED(hResult))
				throw false;
		}
		

		{
			D3D11_RASTERIZER_DESC desc;
			ZeroMemory(&desc, sizeof(D3D11_RASTERIZER_DESC));
			desc.FillMode = D3D11_FILL_SOLID;
			desc.CullMode = D3D11_CULL_BACK;
			desc.FrontCounterClockwise = false;
			desc.DepthBias = 0;
			desc.DepthBiasClamp = 0;
			desc.SlopeScaledDepthBias = 0;
			desc.DepthClipEnable = false;
			desc.ScissorEnable = false;
			desc.MultisampleEnable = true;
			desc.AntialiasedLineEnable = false;
			hResult = pDevice->CreateRasterizerState(&desc, &pNormalRasterizerState);
			if (FAILED(hResult))
				throw false;
		}
		

	}


	void Direct3D::createBlendState()
	{
		D3D11_BLEND_DESC BlendState;
		ZeroMemory(&BlendState, sizeof(D3D11_BLEND_DESC));
		
		BlendState.IndependentBlendEnable = FALSE;
		BlendState.AlphaToCoverageEnable = FALSE;

		auto& bs = BlendState.RenderTarget[0];
		
		bs.BlendEnable = TRUE;
		/*bs.SrcBlend = D3D11_BLEND_SRC_ALPHA;
		bs.DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		bs.BlendOp = D3D11_BLEND_OP_ADD;
		bs.SrcBlendAlpha = D3D11_BLEND_ONE;
		bs.DestBlendAlpha = D3D11_BLEND_ONE;// D3D11_BLEND_ZERO;
		bs.BlendOpAlpha = D3D11_BLEND_OP_ADD;
		*/

		bs.SrcBlend = D3D11_BLEND_SRC_ALPHA;
		bs.DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		bs.BlendOp = D3D11_BLEND_OP_ADD;
		bs.SrcBlendAlpha = D3D11_BLEND_SRC_ALPHA;
		bs.DestBlendAlpha = D3D11_BLEND_DEST_ALPHA;// D3D11_BLEND_ZERO;
		bs.BlendOpAlpha = D3D11_BLEND_OP_ADD;


		bs.RenderTargetWriteMask = 7;

		HRESULT hResult = pDevice->CreateBlendState(&BlendState, &g_pBlendStateBlend);
		if (FAILED(hResult))
			throw false;
	}

	void Direct3D::shutdown()
	{

		SAFE_RELEASE(pNormalRasterizerState);
		SAFE_RELEASE(pWiresRasterizerState);
		SAFE_RELEASE(pStateZBufferOff);
		SAFE_RELEASE(pStateNormal);
		SAFE_RELEASE(pSamplerLinear);
		SAFE_RELEASE(g_pBlendStateBlend);
		SAFE_RELEASE(pDepthView);
		SAFE_RELEASE(pRenderTarget);
		SAFE_RELEASE(pSwapChain);
		SAFE_RELEASE(pContext);
		SAFE_RELEASE(pDevice);
	}

	void Direct3D::present()
	{
		pSwapChain->Present(0, 0);
	}


	void Direct3D::clear()
	{
		float backgroundColor[4] = { 50. / 255., 50. / 255., 100. / 255., 1. };

		pContext->ClearRenderTargetView(pRenderTarget, reinterpret_cast<const float*>(&backgroundColor));

		pContext->ClearDepthStencilView(pDepthView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	}


	ID3D11ShaderResourceView* Direct3D::createTexture(std::wstring filename)
	{
		if (m_textures.find(filename) == m_textures.end())
		{
			ID3D11ShaderResourceView* pTextureRV = nullptr;

			if (FAILED(D3DX11CreateShaderResourceViewFromFile(pDevice, filename.c_str(), NULL, NULL, &pTextureRV, NULL)))
				return nullptr;

			m_textures[filename] = pTextureRV;
		}

		return m_textures[filename];
	}


	/*


	void Direct3D::getTextureDesc(ID3D11ShaderResourceView* pTextureRV, D3D11_TEXTURE2D_DESC& desc)
	{
		ID3D11Texture2D* pTextureInterface = 0;
		ID3D11Resource* res;
		pTextureRV->GetResource(&res);
		res->QueryInterface<ID3D11Texture2D>(&pTextureInterface);

		pTextureInterface->GetDesc(&desc);

		if (pTextureInterface) pTextureInterface->Release();
		if (res) res->Release();
	}


	Texture* Direct3D::createTexture(wstring filename)
	{
		ID3D11ShaderResourceView* pTextureRV = nullptr;
		D3D11_TEXTURE2D_DESC desc = { 0 };

		if (textures.find(filename) != textures.end())
		{
			pTextureRV = textures[filename];
		}
		else
		{
			if (FAILED(D3DX11CreateShaderResourceViewFromFile(pDevice, filename.c_str(), NULL, NULL, &pTextureRV, NULL)))
				return nullptr;

			textures[filename] = pTextureRV;
		}

		getTextureDesc(pTextureRV, desc);

		Texture* texture = new Texture;
		texture->resource = pTextureRV;
		texture->width = desc.Width;
		texture->height = desc.Height;

		return texture;
	}

	*/

	int Direct3D::getClientWidth()
	{
		return client_width;
	}

	int Direct3D::getClientHeight()
	{
		return client_height;
	}

	ID3D11RenderTargetView* Direct3D::getRenderTarget()
	{
		return pRenderTarget;
	}
	ID3D11BlendState* Direct3D::getBlendState()
	{
		return g_pBlendStateBlend;
	}
	ID3D11SamplerState* Direct3D::getSamplerState()
	{
		return pSamplerLinear;
	}

	void Direct3D::setRenderTarget(ID3D11RenderTargetView* rtview, ID3D11DepthStencilView* dsview)
	{
		pContext->OMSetRenderTargets(1, &rtview, dsview);
	}
	
	void Direct3D::setBlendState(ID3D11BlendState* bstate)
	{
		pContext->OMSetBlendState(bstate, nullptr, 0xFFFFFFFFu);
	}

	void Direct3D::setSamplerState(ID3D11SamplerState* sstate)
	{
		pContext->PSSetSamplers(0, 1, &sstate);
	}
		
}