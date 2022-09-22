#pragma once

#include "Model.h"
#include "Scene3D.h"
#include <string>

namespace Scene3D {
	
	using namespace std;

	class ModelLoader
	{
		Scene3D* pScene;
		ID3D11ShaderResourceView* loadTexture(wstring);
	public:
		ModelLoader(Scene3D* pS) : pScene(pS) {};
		Model* loadModel(const wstring s);
	};

}

