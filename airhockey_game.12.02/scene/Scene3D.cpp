#include "pch.h"
#include "Scene3D.h"
//#include "Model.h"
//#include "ModelLoader.h"

namespace Scene3D {

	void Scene3D::DXCreateDevice()
	{
		HR(D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			D3D11_CREATE_DEVICE_DEBUG,
			0,
			0,
			D3D11_SDK_VERSION,
			&pDevice,
			&featureLevel,
			&pContext
		));
	}


	/*void Scene3D::DXLoadShaders()
	{
		ID3D11VertexShader* pVShader = nullptr;
		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
		ID3DBlob* errorBuffer = nullptr;
		ID3DBlob* vsBuffer = nullptr;

		try
		{
			HR(D3DX11CompileFromFile(
				TEXT("VertexShader.fx"),
				0,
				0,
				"VS_Main",
				"vs_4_0",
				shaderFlags,
				0,
				0,
				&vsBuffer,
				&errorBuffer,
				0
			));

			HR(pDevice->CreateVertexShader(
				vsBuffer->GetBufferPointer(),
				vsBuffer->GetBufferSize(),
				0,
				&pVShader
			));

		}
		catch (int)
		{
			if (vsBuffer)
				vsBuffer->Release();

			if (errorBuffer) {
				OutputDebugStringA((char*)errorBuffer->GetBufferPointer());
				errorBuffer->Release();
			}

			throw 0;
		}

		ID3D11PixelShader* pPixelShader = nullptr;
		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
		ID3DBlob* errorBuffer = nullptr;
		ID3DBlob* psBuffer = nullptr;

		try {
			HR(D3DX11CompileFromFile(
				filename.c_str(),
				0,
				0,
				"PS_Main",
				"ps_4_0",
				shaderFlags,
				0,
				0,
				&psBuffer,
				&errorBuffer,
				0
			));



			HR(pDevice->CreatePixelShader(
				psBuffer->GetBufferPointer(),
				psBuffer->GetBufferSize(),
				0,
				&pPixelShader
			));

		}
		catch (int)
		{
			if (psBuffer)
				psBuffer->Release();

			if (errorBuffer) {
				OutputDebugStringA((char*)errorBuffer->GetBufferPointer());
				errorBuffer->Release();
			}

			throw 0;
		}




		D3D11_INPUT_ELEMENT_DESC layout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
				  D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
				  D3D11_INPUT_PER_VERTEX_DATA, 0 },
				  //{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12,
				  //	  D3D11_INPUT_PER_VERTEX_DATA, 0 },
				  //{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 20,
				  //	  D3D11_INPUT_PER_VERTEX_DATA, 0 },
		};

		HR(pDevice->CreateInputLayout(
			layout,
			3,
			vsBuffer->GetBufferPointer(),
			vsBuffer->GetBufferSize(),
			&pInputLayout
		));

	}
	
	
	
	void Scene3D::DXCreateSemplerState() {

		D3D11_SAMPLER_DESC sampDesc;
		ZeroMemory(&sampDesc, sizeof(sampDesc));
		sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
		sampDesc.MinLOD = 0;
		sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

		HR(pDevice->CreateSamplerState(&sampDesc, &pSamplerLinear));
	}
	

	void Scene3D::DXCreateConstantBuffers()
	{
		// Scene common buffer
		{
			D3D11_BUFFER_DESC description;
			description.ByteWidth = sizeof(VS_SCENE_CONSTANT_BUFFER);
			description.Usage = D3D11_USAGE_DYNAMIC;
			description.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
			description.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			description.MiscFlags = 0;
			description.StructureByteStride = 0;

			D3D11_SUBRESOURCE_DATA data;
			data.pSysMem = &SceneConstantBuffer;
			data.SysMemPitch = 0;
			data.SysMemSlicePitch = 0;

			HR(pDevice->CreateBuffer(&description, &data, &pDXSceneConstantBuffer));
			
		}
		
		// Objects buffer
		{

			D3D11_BUFFER_DESC description;
			description.ByteWidth = sizeof(VS_MODEL_CONSTANT_BUFFER);
			description.Usage = D3D11_USAGE_DYNAMIC;
			description.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
			description.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			description.MiscFlags = 0;
			description.StructureByteStride = 0;

			D3D11_SUBRESOURCE_DATA data;
			data.pSysMem = &modelConstantBuffer;
			data.SysMemPitch = 0;
			data.SysMemSlicePitch = 0;

			HR(pDevice->CreateBuffer(&description, &data, &pDXModelConstantBuffer));
		}
		
	}

	
	
	
	*/


	void Scene3D::DXCreateSwapChain()
	{

		DXGI_SWAP_CHAIN_DESC sd;
		sd.BufferDesc.Width = width;
		sd.BufferDesc.Height = height;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.BufferCount = 1;
		sd.OutputWindow = hWnd;
		sd.Windowed = true;
		sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		sd.Flags = 0;

		IDXGIFactory* dxgiFactory = nullptr;
		IDXGIDevice* dxgiDevice = nullptr;
		IDXGIAdapter* dxgiAdapter = nullptr;

		try {
			HR(pDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice));
			HR(dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&dxgiAdapter));
			HR(dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&dxgiFactory));
			
			HR(dxgiFactory->CreateSwapChain(pDevice, &sd, &pSwapChain));
		}
		catch (int)
		{
			SafeRelease(dxgiFactory);
			SafeRelease(dxgiAdapter);
			SafeRelease(dxgiDevice);
			throw 0;
		}

		SafeRelease(dxgiFactory);
		SafeRelease(dxgiAdapter);
		SafeRelease(dxgiDevice);
	}

	void Scene3D::DXCreateRenderTarget()
	{
		HR(pSwapChain->GetBuffer(
			0,
			__uuidof(ID3D11Texture2D),
			reinterpret_cast<void**>(&backBuffer)
		));

		HR(pDevice->CreateRenderTargetView(backBuffer, 0, &pRenderTargetView));
	}

	void Scene3D::DXCreateDepthStencilBuffer()
	{
		D3D11_TEXTURE2D_DESC depthStencilDesc;
		depthStencilDesc.Width = width;
		depthStencilDesc.Height = height;
		depthStencilDesc.MipLevels = 1;
		depthStencilDesc.ArraySize = 1;
		depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilDesc.SampleDesc.Count = 1;
		depthStencilDesc.SampleDesc.Quality = 0;
		depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
		depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		depthStencilDesc.CPUAccessFlags = 0;
		depthStencilDesc.MiscFlags = 0;

		HR(pDevice->CreateTexture2D( &depthStencilDesc, 0, &pDepthStencilBuffer));
		HR(pDevice->CreateDepthStencilView( pDepthStencilBuffer, 0, &pDepthStencilView));
	}
	
	

	void Scene3D::DXSetPipeline()
	{
		D3D11_VIEWPORT vp = {
			0.0f,
			0.0f,
			static_cast<float>(width),
			static_cast<float>(height),
			0.0f,
			1.0f
		};

		pContext->OMSetRenderTargets(
			1,
			&pRenderTargetView,
			pDepthStencilView
		);

		pContext->RSSetViewports(1, &vp);
		//pContext->IASetInputLayout(pInputLayout);
		//pContext->VSSetConstantBuffers(0, 1, &pDXSceneConstantBuffer);
		//pContext->VSSetConstantBuffers(1, 1, &pDXModelConstantBuffer);
	}


	bool Scene3D::DXSetup()
	{

		try {
			DXCreateDevice();
			DXCreateSwapChain();
			DXCreateRenderTarget();
			DXCreateDepthStencilBuffer();
			//DXLoadShaders();
			DXSetPipeline();
		}
		catch (int)
		{
			return false;
		}
		
		return true;
	}

	void Scene3D::DXDestroy()
	{
		SafeRelease(pDepthStencilView);
		SafeRelease(pDepthStencilBuffer);
		SafeRelease(pRenderTargetView);
		SafeRelease(backBuffer);
		SafeRelease(pSwapChain);
		SafeRelease(pContext);
		SafeRelease(pDevice);
	}





	Scene3D::Scene3D(HWND _hWnd) : hWnd(hWnd)
	{
		RECT rc;
		GetClientRect(hWnd, &rc);
		width = rc.right - rc.left;
		height = rc.bottom - rc.top;

		//pModelLoader = new ModelLoader(this);

		if (DXSetup() == false)
		{
			DXDestroy();
			throw wstring(L"Не удалось создать объект");
		}
	}

	void Scene3D::DestroyResources()
	{
		/*
		map<wstring, Geometry*>::iterator itg;
		for (itg = geometry.begin(); itg != geometry.end(); itg++)
		{
			delete itg->second;
		}
		
		map<wstring, ID3D11ShaderResourceView*>::iterator itt;
		for (itt = textures.begin(); itt != textures.end(); itt++)
		{
			delete itt->second;
		}

		vector<Model*>::iterator itm;
		for (itm = models.begin(); itm != models.end(); itm++)
		{
			delete (*itm);
		}

		vector<Light*>::iterator itl;
		for (itl = lights.begin(); itl != lights.end(); itl++)
		{
			delete (*itl);
		}


		delete pVertexShader;

		SafeRelease(pSamplerLinear);
		SafeRelease(pixelShader);

		delete pModelLoader;
		*/
		
	}

	Scene3D::~Scene3D()
	{
		DestroyResources();
		DXDestroy();
	}

	/*
	
	IModel* Scene3D::CreateModel(const wstring filename)
	{
		Model* pModel = pModelLoader->loadModel(filename);
		models.push_back(pModel);
		return pModel;
	}

	ILight* Scene3D::CreateLight()
	{
		Light* pLight = new Light;
		lights.push_back(pLight);
		return pLight;
	}

	*/

	void Scene3D::render()
	{
		pContext->ClearRenderTargetView(pRenderTargetView, backgroundColor);
		pContext->ClearDepthStencilView( pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0 );
		
		//pContext->VSSetShader(pVertexShader->pShader, 0, 0);
		//pContext->PSSetShader(pixelShader, 0, 0);
		//pContext->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		/*
		vector<Model*>::iterator i;
		for (i = models.begin(); i < models.end(); i++)
		{
			renderModel((*i));
		}
		*/
		

		pSwapChain->Present(0, 0);
	}

	/*
	void Scene3D::renderModel(Model* model)
	{
		
		auto it = geometry.find(model->geometry);
		
		if (it == geometry.end()) 
			return;

		unsigned int stride = sizeof(Vertex);
		unsigned int offset = 0;
		
		XMMATRIX mx = model->mx * camera.mx;
		XMMATRIX mxFinal = XMMatrixTranspose(mx);
		XMFLOAT4X4 M;
		XMStoreFloat4x4(&M, mxFinal);
		

	pContext->UpdateSubresource(pDXSceneConstantBuffer, 0, 0, &SceneConstantBuffer, 0, 0);

	Geometry* g = it->second;

	for (int i = 0; i < g->meshes.size(); i++)
	{
		Mesh* mesh = g->meshes[i];
		ID3D11ShaderResourceView* texture = textures.find(mesh->texture)->second;

		pContext->UpdateSubresource(pDXModelConstantBuffer, 0, NULL, &modelConstantBuffer, 0, 0);
		pContext->PSSetShaderResources(0, 1, &texture);
		pContext->IASetVertexBuffers(0, 1, &mesh->dxVertexBuffer, &stride, &offset);
		pContext->IASetIndexBuffer(mesh->dxIndexBuffer, DXGI_FORMAT_R32G32B32_UINT, offset);
		pContext->DrawIndexed(mesh->indexCount, 0, 0);

	}
	}
	
	*/
	
}