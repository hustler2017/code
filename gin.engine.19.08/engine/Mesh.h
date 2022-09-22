#pragma once
#include "pch.h"
#include "VertexData.h"
#include "IMeshShaderResources.h"
#include "MeshAnimation.h"
#include <string>
#include <map>
#include "AABB.h"
#include <map>
#include "IMeshShader.h"

namespace Engine
{
	class IMeshShader;
	class IMeshShaderResources;

	class Mesh
	{
	protected:
		
		std::map<std::string, IMeshShaderResources*>  m_resources;
		VertexData m_vertexData;
		std::map<std::string, MeshAnimation*> m_animations;
		MeshAnimation* m_currentAnimation;
		std::vector<std::wstring> m_textures;
		IMeshShader* m_shader;
		AABB* m_aabb;

	protected:
		AABB* createAABB();
	public:
		Mesh();
		~Mesh();
		
		IVertexData* getVertexData();

		std::wstring getTexture(unsigned int channel);
		unsigned int getTextureChannels();		
		void addTexture(const std::wstring& texture, unsigned int channel);
		void addTexture(const std::wstring& texture);

		std::vector<std::wstring>* getTextures();


		MeshAnimation* getCurrentAnimation();
		void addAnimation(std::string key, MeshAnimation* anim);
		std::vector<std::string> getAnimationNames();
		void startAnimation(std::string key);
		MeshAnimation* getAnimation(std::string key);
		void setShader(IMeshShader* shader);
		void render();

		IMeshShaderResources* getShaderResources(std::string key);
		void setShaderResources(IMeshShaderResources* res, std::string key);
		
		AABB* getAABB();
		void calculateAABB();
		void updateResources();
		
	};
}
