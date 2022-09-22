#include "pch.h"
#include "FbxHeaders.h"
#include "FbxHelperFunctions.h"
#include "FBXModelLoader.h"
#include "FBXMeshLoader.h"


namespace Engine
{
	using namespace fbxsdk;

		
	
	Model* FBXModelLoader::load(Model* model, std::wstring filename)
	{
		std::string cFilename = std::string(filename.begin(), filename.end());

		FbxManager* fbxManager = FbxManager::Create();

		fbxManager->SetIOSettings(FbxIOSettings::Create(fbxManager, IOSROOT));

		FbxImporter* fbxImporter = FbxImporter::Create(fbxManager, "name001");
		fbxImporter->Initialize(cFilename.c_str(), -1, fbxManager->GetIOSettings());

		FbxScene* scene = FbxScene::Create(fbxManager, "scene001");

		fbxImporter->Import(scene);
		fbxImporter->Destroy();

		std::list<FbxMesh*> fbxMeshes;
		createMeshlist(scene->GetRootNode(), &fbxMeshes);

		for (const auto& pFbxMesh : fbxMeshes)
		{
			Mesh* mesh = new Mesh();
			FBXMeshLoader::load(mesh, pFbxMesh);
			model->m_meshes.push_back(mesh);
		}

		fbxManager->Destroy();

		return model;
	}


	

}
