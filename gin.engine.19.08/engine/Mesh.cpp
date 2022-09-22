#include "pch.h"
#include "Mesh.h"

namespace Engine
{
	Mesh::Mesh() 
		: m_currentAnimation(nullptr),
		m_shader(nullptr),
		m_aabb(nullptr)
	{

	}

	Mesh::~Mesh()
	{
		for (auto& pair : m_animations)
			delete pair.second;
		for (auto& resources : m_resources)
			delete resources.second;

		delete m_aabb;
	}

	void Mesh::addAnimation(std::string key, MeshAnimation* anim)
	{
		auto it = m_animations.find(key);
		if (it != m_animations.end())
		{
			delete it->second;
		}

		m_animations[key] = anim;

		if (!m_currentAnimation) m_currentAnimation = anim;
	}

	void Mesh::addTexture(const std::wstring& texture, UINT channel)
	{
		m_textures[channel] = texture;
	}

	std::vector<std::wstring>* Mesh::getTextures()
	{
		return &m_textures;
	}

	std::wstring Mesh::getTexture(UINT channel)
	{
		if (m_textures.size() > channel)
		{
			return m_textures[channel];
		}

		return std::wstring(L"");
	}

	UINT Mesh::getTextureChannels()
	{
		return m_textures.size();
	}

	MeshAnimation* Mesh::getCurrentAnimation()
	{
		return m_currentAnimation;
	}

	void Mesh::startAnimation(std::string key)
	{
		if (m_currentAnimation)
		{
			m_currentAnimation->stop();
			m_currentAnimation->reset();
		}
		
		m_currentAnimation = getAnimation(key);
		if (m_currentAnimation)
		{
			m_currentAnimation->start();
		}
	}

	std::vector<std::string> Mesh::getAnimationNames()
	{
		std::vector<std::string> names;
		for (const auto& animation : m_animations)
		{
			names.push_back(animation.first);
		}

		return names;
	}

	void Mesh::addTexture(const std::wstring& texture)
	{
		m_textures.push_back(texture);
	}

	IVertexData* Mesh::getVertexData()
	{
		return &m_vertexData;
	}


	IMeshShaderResources* Mesh::getShaderResources(std::string key)
	{
		auto it = m_resources.find(key);

		if (it != m_resources.end())
		{
			return m_resources[key];
		}

		return nullptr;
	}

	void Mesh::updateResources()
	{
		for (auto& res : m_resources)
		{
			res.second->update();
		}
	}

	AABB* Mesh::createAABB()
	{
		int count = m_vertexData.getCoordinatesCount();

		if (count == 0) return nullptr;

		AABB* aabb = new AABB();

		aabb->points[0] = m_vertexData.getCoordinates(0);
		aabb->points[1] = m_vertexData.getCoordinates(0);

		Vector3 coords;
		for (int i = 0; i < count; i++)
		{
			coords = m_vertexData.getCoordinates(i);

			if (aabb->points[0].x < coords.x) aabb->points[0].x = coords.x;
			if (aabb->points[0].y < coords.y) aabb->points[0].y = coords.y;
			if (aabb->points[0].z < coords.z) aabb->points[0].z = coords.z;

			if (aabb->points[1].x > coords.x) aabb->points[1].x = coords.x;
			if (aabb->points[1].y > coords.y) aabb->points[1].y = coords.y;
			if (aabb->points[1].z > coords.z) aabb->points[1].z = coords.z;
		}

		return aabb;
	}

	void Mesh::calculateAABB()
	{
		if (m_aabb) delete m_aabb;
		m_aabb = createAABB();
	}

	void Mesh::setShaderResources(IMeshShaderResources* res, std::string key)
	{
		auto it = m_resources.find(key);

		if (it != m_resources.end())
		{
			return;
		}

		m_resources[key] = res;
	}

	void Mesh::setShader(IMeshShader* shader)
	{
		if (m_resources.find(shader->getName()) == m_resources.end())
		{
			shader->createResources(this);
		}		
		m_shader = shader;
	}

	void Mesh::render()
	{
		if (m_shader) {
			m_shader->render(this);
		}
	}

	AABB* Mesh::getAABB()
	{
		if (m_aabb == nullptr)
		{
			m_aabb = createAABB();
		}

		return m_aabb;
	}

	MeshAnimation* Mesh::getAnimation(std::string key)
	{
		auto it = m_animations.find(key);
		if (it != m_animations.end())
		{
			return it->second;
		}

		return nullptr;
	}
}