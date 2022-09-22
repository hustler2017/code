#pragma once
#include "pch.h"
#include "Mesh.h"
#include "NavMesh.h"
#include "FbxHeaders.h"
#include <string>

class Mesh;

namespace Engine
{
	class FBXMeshLoader
	{
	public:
		static void loadPolygons(Mesh* pMesh, FbxMesh* pFbxMesh);
		static void loadControlPoints(Mesh* pMesh, FbxMesh* pFbxMesh);
		//static void loadWeights(Mesh* pMesh, FbxMesh* pFbxMesh);
		static MeshAnimation* loadAnimation(FbxMesh* pFbxMesh);
		static MeshAnimation* loadAnimation(std::wstring filename);
		//static bool loadAnimation(Mesh* pMesh, std::wstring filename);
		static void loadTexture(Mesh* pMesh, FbxMesh* pFbxMesh);
		static void loadBonesAndWeights(Mesh* pMesh, FbxMesh* pFbxMesh);
		static void load(Mesh* pMesh, std::wstring filename);
		static void load(Mesh* pMesh, FbxMesh* pFbxMesh);
		//static void load(Mesh* pMesh, FbxMesh* pFbxMesh);
		static void loadNormals(Mesh* pMesh, FbxMesh* pFbxMesh);
		static void loadColors(Mesh* pMesh, FbxMesh* pFbxMesh);
		static void loadUV(Mesh* pMesh, unsigned int channel, FbxMesh* pFbxMesh);
	};

}

