#pragma once

#include "interfaces.h"













#include "common.h"
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include <dxerr.h>
//#include "Model.h"
//#include "Light.h"
//#include "ModelLoader.h"
//#include "Camera.h"
#include <vector>
#include <map>
#include <codecvt>
#include <locale>




namespace Scene3D {

	using namespace std;





	/*
	class Geometry
	{
	public:
		vector<Mesh*> meshes;
		~Geometry() {
			for (auto it = meshes.begin(); it != meshes.end(); it++)
			{
				delete (*it);
			}
		}
	};



	struct LIGHT_BUFFER {
		XMFLOAT3 position;
		XMFLOAT4 color;
		float range;
	};

	struct VS_SCENE_CONSTANT_BUFFER
	{
		XMFLOAT4X4 mView;
		XMFLOAT4X4 mProj;
		int numLights;
		LIGHT_BUFFER lights[10];
	};

	struct VS_MODEL_CONSTANT_BUFFER
	{
		XMFLOAT4X4 mWorld;
	};

	
	*/

	




	class Scene3D : public IScene3D
	{
		//friend class ModelLoader;
	public:
		//Camera camera;
		Scene3D(HWND hWnd);
		~Scene3D();

		//virtual IModel* CreateModel(const wstring filename);
		//virtual ILight* CreateLight();
		virtual void render();

	private:

		//VS_SCENE_CONSTANT_BUFFER SceneConstantBuffer;
		//VS_MODEL_CONSTANT_BUFFER modelConstantBuffer;
		//ID3D11Buffer* pDXSceneConstantBuffer = nullptr;
		//ID3D11Buffer* pDXModelConstantBuffer = nullptr;

		int width;
		int height;

		float backgroundColor[4] = {0.0f, 0.0f, 0.0f, 0.0f};

		
		//ModelLoader* pModelLoader = nullptr;

		HWND hWnd;
		D3D_FEATURE_LEVEL featureLevel;
		ID3D11Device* pDevice = nullptr;
		ID3D11DeviceContext* pContext = nullptr;
		IDXGISwapChain* pSwapChain = nullptr;
		ID3D11RenderTargetView* pRenderTargetView = nullptr;
		ID3D11Texture2D* backBuffer = nullptr;
		ID3D11Texture2D* pDepthStencilBuffer = nullptr;
		ID3D11DepthStencilView* pDepthStencilView = nullptr;
		//ID3D11InputLayout* pInputLayout = nullptr;
		ID3D11VertexShader* pVertexShader = nullptr;
		ID3D11PixelShader* pixelShader = nullptr;
		//ID3D11SamplerState* pSamplerLinear = nullptr;
		//vector<Light*> lights;
		//vector<Model*> models;
		//map<wstring, Geometry*>  geometry;
		//map<wstring, ID3D11ShaderResourceView*> textures;		

		bool DXSetup();
		void DXDestroy();
		void DestroyResources();

		void DXCreateDevice();
		void DXCreateSwapChain();
		void DXCreateRenderTarget();
		void DXCreateDepthStencilBuffer();
		void DXLoadShaders();
		//void DXCreateConstantBuffers();
		//void DXCreateSemplerState();		
		void DXSetPipeline();

		//ID3D11PixelShader* LoadPixelShader(wstring filename);
		//VertexShader* LoadVertexShader(wstring filename);
		//void renderModel(Model*);
	};
}
