#include "pch.h"
#include "ModelLoader.h"
#include <string>
#include <codecvt>
#include <locale>

#pragma comment(lib, "assimp-vc142-mtd.lib")
#pragma comment(lib, "zlibd.lib")

#include <assimp/cimport.h>        
#include <assimp/scene.h>          
#include <assimp/postprocess.h>    

namespace Scene3D {

	Model* ModelLoader::loadModel(const wstring filename)
	{

        string cfilename = WToS(filename);

        const struct aiScene* scene = aiImportFile(
            cfilename.c_str(),
            aiProcess_CalcTangentSpace |
            aiProcess_Triangulate |
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType
        );

        if (scene == nullptr)
        {
            OutputDebugStringA(aiGetErrorString());
            return nullptr;
        }

        if (scene->HasMeshes() == false)
        {
            OutputDebugStringA("ModelLoader::loadModel - no meshes in scene!");
            return nullptr;
        }

        Geometry* geometry = new Geometry;
        Mesh* mesh = nullptr;

        try {

            for (int i = 0; i < scene->mNumMeshes; i++)
            {
                aiMesh* aimesh = scene->mMeshes[i];

                /*if (aimesh->mPrimitiveTypes != 4)
                {
                    OutputDebugStringA("ModelLoader::loadModel - примитивы сетки не треугольники!");
                    throw 0;
                }*/

                mesh = new Mesh;

                // buffer -------------------------------------------------------------------
                ID3D11Buffer* pVertexBuffer = nullptr;

                D3D11_BUFFER_DESC vbd = { 0 };
                vbd.Usage = D3D11_USAGE_IMMUTABLE;
                vbd.ByteWidth = sizeof(Vertex) * aimesh->mNumVertices;
                vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
                vbd.MiscFlags = 0;
                vbd.StructureByteStride = 0;

                D3D11_SUBRESOURCE_DATA vertexData;
                vertexData.pSysMem = static_cast<void*>(aimesh->mVertices);

                HR(pScene->pDevice->CreateBuffer(&vbd, &vertexData, &pVertexBuffer));

                mesh->dxVertexBuffer = pVertexBuffer;

                // indeces -------------------------------------------------------------------

                ID3D11Buffer* pIndexBuffer = nullptr;

                D3D11_BUFFER_DESC ibd;
                ibd.Usage = D3D11_USAGE_IMMUTABLE;
                ibd.ByteWidth = sizeof(Vertex) * 3 * aimesh->mNumFaces;
                ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
                ibd.CPUAccessFlags = 0;
                ibd.MiscFlags = 0;
                ibd.StructureByteStride = 0;

                D3D11_SUBRESOURCE_DATA indexData;
                indexData.pSysMem = static_cast<void*>(aimesh->mFaces);

                HR(pScene->pDevice->CreateBuffer(&ibd, &indexData, &pIndexBuffer));

                mesh->dxIndexBuffer = pIndexBuffer;

                // texture -------------------------------------------------------------------
                aiString aiTexFile;
                aiMaterial * material = scene->mMaterials[aimesh->mMaterialIndex];
                aiGetMaterialString(material, _AI_MATKEY_TEXTURE_BASE, aiTextureType_DIFFUSE, 0, &aiTexFile);

                wstring texFile(SToW(string(aiTexFile.C_Str())));

                if (pScene->textures.find(texFile) != pScene->textures.end())
                {
                    ID3D11ShaderResourceView* pTextureRV = nullptr;

                    HR(D3DX11CreateShaderResourceViewFromFile(
                        pScene->pDevice,
                        texFile.c_str(),
                        NULL,
                        NULL,
                        &pTextureRV,
                        NULL
                    ));

                    pScene->textures.insert(pair<wstring, ID3D11ShaderResourceView*>(texFile, pTextureRV));
                    mesh->texture = texFile;

                    geometry->meshes.push_back(mesh);
                }
            }
        } 
        catch (int)
        {
            if (mesh) delete mesh;
            delete geometry;
            aiReleaseImport(scene);
            return nullptr;
        }

        pScene->geometry.insert(pair<wstring, Geometry*>(filename, geometry));

        Model* model = new Model;
        model->geometry = filename;

        return model;
	}

}

