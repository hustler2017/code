#pragma once
#include "pch.h"
#include <d3d11.h>   
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <dxerr.h>
#include <string>
#include <list>
#include <map>

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(x) if(x) { x->Release(); x = nullptr; }
#endif



namespace Graphics
{
	class Direct3D
	{
	private:
		HWND hWnd;

		ID3D11RenderTargetView* pRenderTarget = nullptr;
		ID3D11DepthStencilView* pDepthView = nullptr;
		ID3D11BlendState* g_pBlendStateBlend = nullptr;
		ID3D11SamplerState* pSamplerLinear = nullptr;
		ID3D11DepthStencilState* pStateNormal = nullptr;
		ID3D11DepthStencilState* pStateZBufferOff = nullptr;
		ID3D11RasterizerState* pNormalRasterizerState = nullptr;
		ID3D11RasterizerState* pWiresRasterizerState = nullptr;



		std::map<std::wstring, ID3D11ShaderResourceView*> m_textures;

		int client_height;
		int client_width;

		void init();
		void createDevice();
		void createSwapChain();
		void createRenderTarget();
		void createDepthBuffer();
		void createBlendState();
		void createRasterizerState();
		void createSamplers();
		void setup();

		void shutdown();
		void clearResources();

	public:

		ID3D11RenderTargetView* getRenderTarget();
		ID3D11BlendState* getBlendState();
		ID3D11SamplerState* getSamplerState();

		void setRenderTarget(ID3D11RenderTargetView*, ID3D11DepthStencilView*);
		void setBlendState(ID3D11BlendState*);
		void setSamplerState(ID3D11SamplerState*);
		void turnZBuffer(bool);
		void turnWireMode(bool);
		ID3D11ShaderResourceView* createTexture(std::wstring filename);
		
		IDXGISwapChain* pSwapChain = nullptr;
		ID3D11Device* pDevice = nullptr;
		ID3D11DeviceContext* pContext = nullptr;

		Direct3D(HWND);
		~Direct3D();
		void clear();
		void present();
		int getClientWidth();
		int getClientHeight();
	};
}



