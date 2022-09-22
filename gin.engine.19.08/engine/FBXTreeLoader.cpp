#include "pch.h"
#include "FbxHeaders.h"
#include "FBXTreeLoader.h"
#include "FbxHelperFunctions.h"
#include "Sprite.h"
#include <map>
#include "FBXModelLoader.h"
#include "FBXMeshLoader.h"
#include "Tree.h"

namespace Engine
{

	void parseNode(FbxNode* node, 
		std::list<Object*>* objects, 
		Graphics::Direct3D* d3d,
		std::map<int, Model*>* treeModels
	)
	{
		std::string name = node->GetName();
		if (name.compare(0, 3, "Tree", 0, 3) == 0)
		{
			Tree* tree = new Tree();

			FbxDouble3 tree_translation = node->LclTranslation.Get();
			FbxDouble3 tree_rotation = node->LclRotation.Get();
			FbxDouble3 tree_scaling = node->LclScaling.Get();

			tree->getPosition()->position.x = (float)tree_translation[0];
			tree->getPosition()->position.y = (float)tree_translation[1];
			tree->getPosition()->position.z = (float)tree_translation[2];
			tree->getPosition()->rotation.x = (float)tree_rotation[0];
			tree->getPosition()->rotation.y = (float)tree_rotation[1];
			tree->getPosition()->rotation.z = (float)tree_rotation[2];
			tree->getPosition()->scale.x = (float)tree_scaling[0];
			tree->getPosition()->scale.y = (float)tree_scaling[1];
			tree->getPosition()->scale.z = (float)tree_scaling[2];

			for (int i = 0; i < node->GetChildCount(); i++)
			{
				FbxNode* child = node->GetChild(i);
				std::string childName = child->GetName();

				if (childName.compare(0, 4, "tree", 0, 4) == 0)
				{
					int tree_id = std::stoi(name.substr(5, 2));

					if (treeModels->find(tree_id) == treeModels->end())
					{
						FbxMesh* fbxMesh = child->GetMesh();

						Mesh* mesh = new Mesh();
						FBXMeshLoader::loadPolygons(mesh, fbxMesh);
						FBXMeshLoader::loadControlPoints(mesh, fbxMesh);
						FBXMeshLoader::loadNormals(mesh, fbxMesh);
						FBXMeshLoader::loadTexture(mesh, fbxMesh);

						Model* model = new Model();
						model->calculateAABB();
						model->m_meshes.push_back(mesh);
						(*treeModels)[tree_id] = model;
					}

					tree->setModel((*treeModels)[tree_id]);
				}

				if (childName.compare(0, 4, "leaf", 0, 4) == 0)
				{
					Sprite3D sprite;

					FbxDouble3 leaf_translation = child->LclTranslation.Get();
					FbxDouble3 leaf_scaling = child->LclScaling.Get();

					sprite.position.x = (float)leaf_translation[0];
					sprite.position.y = (float)leaf_translation[1];
					sprite.position.z = (float)leaf_translation[2];
					sprite.scale.x = (float)leaf_scaling[0];
					sprite.scale.y = (float)leaf_scaling[1];
					sprite.scale.z = (float)leaf_scaling[2];

					FbxMesh* fbxMesh = child->GetMesh();
					FbxVector4* points = fbxMesh->GetControlPoints();

					Vector4 rect;

					sprite.rect.x = (float)points[0].mData[0];
					sprite.rect.y = (float)points[0].mData[1];
					sprite.rect.z = (float)points[0].mData[0];
					sprite.rect.w = (float)points[0].mData[1];

					for (int j = 0; j < fbxMesh->GetControlPointsCount(); j++)
					{
						if (points[j].mData[0] < sprite.rect.x) sprite.rect.x = points[j].mData[0];
						if (points[j].mData[1] > sprite.rect.y) sprite.rect.y = points[j].mData[1];
						if (points[j].mData[0] > sprite.rect.z) sprite.rect.z = points[j].mData[0];
						if (points[j].mData[1] < sprite.rect.w) sprite.rect.w = points[j].mData[1];
					}

					if (child->GetMaterialCount())
					{
						FbxSurfaceMaterial* material = child->GetMaterial(0);
						if (material)
						{
							fbxsdk::FbxProperty diffuse_property = material->FindProperty(fbxsdk::FbxSurfaceMaterial::sDiffuse);
							const FbxFileTexture* texture = diffuse_property.GetSrcObject<FbxFileTexture>();
							if (texture)
							{
								std::string c_file(texture->GetFileName());
								sprite.texture = d3d->createTexture(std::wstring(c_file.begin(), c_file.end()));
							}
						}
					}

					tree->sprites.push_back(sprite);
				}
			}

			tree->visible = true;
			objects->push_back(tree);
		}
	}


	void FBXTreeLoader::Load(std::wstring filename, std::list<Object*>* objects, std::map<int, Model*>* treeModels, Graphics::Direct3D* d3d)
	{

		

		std::string cFilename = std::string(filename.begin(), filename.end());

		fbxsdk::FbxManager* fbxManager = fbxsdk::FbxManager::Create();

		fbxManager->SetIOSettings(fbxsdk::FbxIOSettings::Create(fbxManager, IOSROOT));

		fbxsdk::FbxImporter* fbxImporter = fbxsdk::FbxImporter::Create(fbxManager, "name001");
		fbxImporter->Initialize(cFilename.c_str(), -1, fbxManager->GetIOSettings());

		FbxScene* scene = fbxsdk::FbxScene::Create(fbxManager, "scene001");

		fbxImporter->Import(scene);
		fbxImporter->Destroy();

		FbxNode* root = scene->GetRootNode();
		
		for (int i = 0; i < root->GetChildCount(); i++)
		{
			FbxNode* child = root->GetChild(i);
			parseNode(child, objects, d3d, treeModels);
		}

		fbxManager->Destroy();

	}
}