#include "pch.h"
#include "FbxHeaders.h"
#include "FBXMeshLoader.h"
#include "FbxHelperFunctions.h"
#include <DirectXMath.h>

#define MAX_WEIGHTS 4

namespace Engine
{
	using namespace fbxsdk;

	DirectX::XMMATRIX FbxAMatrixToXMMATRIX(FbxAMatrix& fbxmatrix)
	{
		return DirectX::XMMatrixSet(
			fbxmatrix.mData[0].mData[0],
			fbxmatrix.mData[0].mData[1],
			fbxmatrix.mData[0].mData[2],
			fbxmatrix.mData[0].mData[3],

			fbxmatrix.mData[1].mData[0],
			fbxmatrix.mData[1].mData[1],
			fbxmatrix.mData[1].mData[2],
			fbxmatrix.mData[1].mData[3],

			fbxmatrix.mData[2].mData[0],
			fbxmatrix.mData[2].mData[1],
			fbxmatrix.mData[2].mData[2],
			fbxmatrix.mData[2].mData[3],

			fbxmatrix.mData[3].mData[0],
			fbxmatrix.mData[3].mData[1],
			fbxmatrix.mData[3].mData[2],
			fbxmatrix.mData[3].mData[3]
		);
	}


	void GetAnimationRange(FbxMesh* pFbxMesh, FbxTime& start, FbxTime& end)
	{
		FbxAnimStack* lCurrentAnimationStack = FbxCast<FbxAnimStack>(
			pFbxMesh->GetScene()->GetSrcObject(
				FbxCriteria::ObjectType(FbxAnimStack::ClassId),
				0
			)
			);
		FbxTakeInfo* lCurrentTakeInfo = pFbxMesh->GetScene()->GetTakeInfo(lCurrentAnimationStack->GetName());
		start = lCurrentTakeInfo->mLocalTimeSpan.GetStart();
		end = lCurrentTakeInfo->mLocalTimeSpan.GetStop();
	}

	int GetAnimationFramesCount(FbxTime& start, FbxTime& end, FbxTime& frameTime)
	{
		int framesCounter = 0;
		for (auto t = start; t < end; t += frameTime, framesCounter++);
		return framesCounter;
	}



	
	void FBXMeshLoader::loadControlPoints(Mesh* pMesh, FbxMesh* pFbxMesh)
	{
		IVertexData* vertexData = pMesh->getVertexData();

		FbxVector4* controlPoints = pFbxMesh->GetControlPoints();
		int controlPointsCount = pFbxMesh->GetControlPointsCount();
		vertexData->setCoordinatesCount(controlPointsCount);

		FbxVector4 v;
		for (int i = 0; i < controlPointsCount; i++)
		{
			v = pFbxMesh->GetControlPointAt(i);
			vertexData->setCoordinates(i, Vector3(v.mData[0], v.mData[1], v.mData[2]));
		}
	}
	
	void FBXMeshLoader::loadPolygons(Mesh* pMesh, FbxMesh* pFbxMesh)
	{
		IVertexData* vertexData = pMesh->getVertexData();

		int polygonCount = pFbxMesh->GetPolygonCount();
		vertexData->setPolygonCount(polygonCount);

		for (int polygonIndex = 0; polygonIndex < polygonCount; polygonIndex++)
		{
			vertexData->setPolygon(
				polygonIndex,
				pFbxMesh->GetPolygonVertex(polygonIndex, 0),
				pFbxMesh->GetPolygonVertex(polygonIndex, 1),
				pFbxMesh->GetPolygonVertex(polygonIndex, 2)
			);
		}
	}
	
	//  нужно обеспечить кол-во каналов до загрузки!
	void FBXMeshLoader::loadUV(Mesh* pMesh, unsigned int channel, FbxMesh* pFbxMesh)
	{
		FbxLayerElementUV* elementUV = pFbxMesh->GetLayer(0)->GetUVs();
		if (elementUV == nullptr)
		{
			OutputDebugString(L"FBXMeshLoader::loadUV отсутствуют координаты UV\n");
			return;
		}

		int uvCount = elementUV->GetDirectArray().GetCount();

		if (uvCount == 0)
		{
			OutputDebugString(L"FBXMeshLoader::loadUV отсутствуют координаты UV\n");
			return;
		}

		IVertexData* vertexData = pMesh->getVertexData();
		UINT vertexDataUVsChannelsCount = vertexData->getUVChannelCount();

		if (channel >= vertexDataUVsChannelsCount)
		{
			vertexData->setUVChannelCount(channel + 1);
		}

		UINT vertexDataUVsCount = vertexData->getUVCount();

		if (vertexDataUVsCount < uvCount)
		{
			vertexData->setUVCount(uvCount);
		}
		
		FbxVector2 v2;
		for (int i = 0; i < uvCount; i++)
		{
			v2 = elementUV->GetDirectArray().GetAt(i);
			vertexData->setUV(channel, i, Vector2(v2.mData[0], v2.mData[1]));
		}

		/*
		FbxVector2 uv;

		IVertexData* vertexData = pMesh->getVertexData();
		FbxLayerElementUV* elementUV = pFbxMesh->GetLayer(0)->GetUVs();
		int polygonsCount = pFbxMesh->GetPolygonCount();

		vertexData->setUVChannelCount(1);
		vertexData->setUVCount(pFbxMesh->GetControlPointsCount());

		for (int p = 0; p < polygonsCount; p++)
		{
			for (int v = 0; v < 3; v++)
			{
				uv = elementUV->GetDirectArray().GetAt(pFbxMesh->GetTextureUVIndex(p, v));
				vertexData->setUV(0, pFbxMesh->GetPolygonVertex(p, v), Vector2(uv.mData[0], uv.mData[1]));
			}
		}
		*/
	}


	void FBXMeshLoader::loadNormals(Mesh* pMesh, FbxMesh* pFbxMesh)
	{
		IVertexData* vertexData = pMesh->getVertexData();
		FbxLayerElementNormal* elementNormal = pFbxMesh->GetLayer(0)->GetNormals();
		int normalsCount = elementNormal->GetDirectArray().GetCount();
		vertexData->setNormalCount(normalsCount);
		FbxVector4 normal;
		for (int i = 0; i < normalsCount; i++)
		{
			normal = elementNormal->GetDirectArray().GetAt(i);
			vertexData->setNormal(i, Vector3(normal.mData[0], normal.mData[1], normal.mData[2]));
		}
	}


	void FBXMeshLoader::loadColors(Mesh* pMesh, FbxMesh* pFbxMesh)
	{
		FbxLayerElementVertexColor* pVertexColorSet = pFbxMesh->GetLayer(0)->GetVertexColors();
		if (!pVertexColorSet) return;

		IVertexData* vertexData = pMesh->getVertexData();
		int count = pVertexColorSet->GetDirectArray().GetCount();

		for (int i = 0; i < count; i++)
		{
			FbxColor c = pVertexColorSet->GetDirectArray().GetAt(i);
			vertexData->setColor(i, Vector4(c.mRed, c.mGreen, c.mBlue, c.mAlpha));
		}
	}

	
	void FBXMeshLoader::load(Mesh* pMesh, std::wstring filename)
	{
		std::string cFilename = std::string(filename.begin(), filename.end());

		fbxsdk::FbxManager* fbxManager = fbxsdk::FbxManager::Create();

		fbxManager->SetIOSettings(fbxsdk::FbxIOSettings::Create(fbxManager, IOSROOT));

		fbxsdk::FbxImporter* fbxImporter = fbxsdk::FbxImporter::Create(fbxManager, "name001");
		fbxImporter->Initialize(cFilename.c_str(), -1, fbxManager->GetIOSettings());

		FbxScene* scene = fbxsdk::FbxScene::Create(fbxManager, "scene001");

		fbxImporter->Import(scene);
		fbxImporter->Destroy();

		FbxMesh* pFbxMesh = findMeshRecurcive(scene->GetRootNode());

		if (pFbxMesh)
		{
			load(pMesh, pFbxMesh);
			MeshAnimation* animation = loadAnimation(pFbxMesh);
			if (animation) {
				pMesh->addAnimation("default", animation);
			}
		}

		fbxManager->Destroy();
	}


	void FBXMeshLoader::load(Mesh* pMesh, FbxMesh* pFbxMesh)
	{
		loadControlPoints(pMesh, pFbxMesh);
		loadPolygons(pMesh, pFbxMesh);
		loadNormals(pMesh, pFbxMesh);
		loadColors(pMesh, pFbxMesh);
		loadUV(pMesh, 0, pFbxMesh);
		loadBonesAndWeights(pMesh, pFbxMesh);
		loadTexture(pMesh, pFbxMesh);
	}

	void FBXMeshLoader::loadBonesAndWeights(Mesh* pMesh, FbxMesh* pFbxMesh)
	{
		struct Weights {
			unsigned int cluster_id[MAX_WEIGHTS];
			float weight[MAX_WEIGHTS];
		};

		int controlPointsCount = pFbxMesh->GetControlPointsCount();

		Weights* weightsBuffer = new Weights[controlPointsCount];
		ZeroMemory(weightsBuffer, sizeof(Weights) * controlPointsCount);

		FbxSkin* lDeformer = static_cast<FbxSkin*>(pFbxMesh->GetDeformer(0, FbxDeformer::eSkin));
		if (lDeformer == nullptr) return;
		int clusterCount = lDeformer->GetClusterCount();

		FbxCluster* cluster;
		int indices_count;
		int* indeces;
		double* weights;

		for (int clusterIndex = 0; clusterIndex < clusterCount; clusterIndex++)
		{
			cluster = lDeformer->GetCluster(clusterIndex);

			indices_count = cluster->GetControlPointIndicesCount();
			indeces = cluster->GetControlPointIndices();
			weights = cluster->GetControlPointWeights();

			for (int i = 0; i < indices_count; i++)
			{
				for (int k = 0; k < MAX_WEIGHTS; k++)
				{
					if (weightsBuffer[indeces[i]].weight[k] == 0)
					{
						weightsBuffer[indeces[i]].weight[k] = weights[i];
						weightsBuffer[indeces[i]].cluster_id[k] = clusterIndex;
						break;
					}
				}


			}
		}


		IVertexData* vertexData = pMesh->getVertexData();
		vertexData->setBoneChannelCount(MAX_WEIGHTS);
		vertexData->setBonesCount(controlPointsCount);

		for (int p = 0; p < controlPointsCount; p++)
		{
			for (int c = 0; c < MAX_WEIGHTS; c++)
			{
				vertexData->setBone(c, p, weightsBuffer[p].cluster_id[c], weightsBuffer[p].weight[c]);
			}
		}
	}
	
	MeshAnimation* FBXMeshLoader::loadAnimation(std::wstring filename)
	{
		std::string cFilename = std::string(filename.begin(), filename.end());

		fbxsdk::FbxManager* fbxManager = fbxsdk::FbxManager::Create();

		fbxManager->SetIOSettings(fbxsdk::FbxIOSettings::Create(fbxManager, IOSROOT));

		fbxsdk::FbxImporter* fbxImporter = fbxsdk::FbxImporter::Create(fbxManager, "name001");
		fbxImporter->Initialize(cFilename.c_str(), -1, fbxManager->GetIOSettings());

		FbxScene* scene = fbxsdk::FbxScene::Create(fbxManager, "scene001");

		fbxImporter->Import(scene);
		fbxImporter->Destroy();

		FbxMesh* pFbxMesh = findMeshRecurcive(scene->GetRootNode());

		MeshAnimation* anim = nullptr;

		if (pFbxMesh)
		{
			anim = loadAnimation(pFbxMesh);	
		}

		fbxManager->Destroy();

		return anim;
	}

	MeshAnimation* FBXMeshLoader::loadAnimation(FbxMesh* pFbxMesh)
	{
		FbxTime start;
		FbxTime end;
		FbxTime frameTime;

		FbxSkin* lDeformer = static_cast<FbxSkin*>(pFbxMesh->GetDeformer(0, FbxDeformer::eSkin));
		if (lDeformer == nullptr) return nullptr;

		GetAnimationRange(pFbxMesh, start, end);

		FbxTime::EMode mode = pFbxMesh->GetScene()->GetGlobalSettings().GetTimeMode();

		frameTime.SetMilliSeconds(1000.0f / 30);
		int framesCount = GetAnimationFramesCount(start, end, frameTime);

		int clusterCount = lDeformer->GetClusterCount();

		MeshAnimation* animation = new MeshAnimation(framesCount, clusterCount);

		DirectX::XMMATRIX matrix;

		FbxAMatrix parent;
		FbxAMatrix clusterMatrix;
		FbxCluster* cluster;
		FbxAMatrix lGlobalPosition;

		int frame = 0;
		for (FbxTime time = start; time < end; time += frameTime)
		{
			for (int i = 0; i < clusterCount; i++)
			{
				cluster = lDeformer->GetCluster(i);
				lGlobalPosition = GetGlobalPosition(pFbxMesh->GetNode(), time);
				getClusterMatrix(cluster, pFbxMesh, lGlobalPosition, clusterMatrix, time);
				matrix = FbxAMatrixToXMMATRIX(clusterMatrix);
				matrix = DirectX::XMMatrixTranspose(matrix);
				animation->addMatrix(frame, i, &matrix);
			}

			frame++;
		}

		return animation;
	}
	
	void FBXMeshLoader::loadTexture(Mesh* pMesh, FbxMesh* pFbxMesh)
	{
		if (pFbxMesh->GetNode()->GetMaterialCount())
		{
			FbxSurfaceMaterial* material = pFbxMesh->GetNode()->GetMaterial(0);
			if (material)
			{
				fbxsdk::FbxProperty diffuse_property = material->FindProperty(fbxsdk::FbxSurfaceMaterial::sDiffuse);
				const FbxFileTexture* texture = diffuse_property.GetSrcObject<FbxFileTexture>();
				if (texture)
				{
					std::string c_file(texture->GetFileName());
					pMesh->addTexture(std::wstring(c_file.begin(), c_file.end()));
				}
			}
		}
	}
}

