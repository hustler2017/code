#pragma once
#include "pch.h"
#include "FbxHeaders.h"
#include <list>

namespace Engine
{
	using namespace fbxsdk;

	FbxAMatrix GetPoseMatrix(FbxPose* pPose, int pNodeIndex);

	FbxAMatrix GetGeometry(FbxNode* pNode);

	void ComputeClusterDeformation(FbxAMatrix& pGlobalPosition,
		FbxMesh* pMesh,
		FbxCluster* pCluster,
		FbxAMatrix& pVertexTransformMatrix,
		FbxTime pTime,
		FbxPose* pPose);


	void getClusterMatrix(FbxCluster* cluster, FbxMesh* mesh, FbxAMatrix& globalPosition, FbxAMatrix& vertexTransformationMatrix, FbxTime time);


	FbxAMatrix GetGlobalPosition(FbxNode* pNode, const FbxTime& pTime);


	FbxMesh* findMeshRecurcive(FbxNode* parentNode);
	void createMeshlist(FbxNode* parentNode, std::list<FbxMesh*>* list);
}
