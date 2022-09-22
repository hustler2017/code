#include "pch.h"
#include "Model.h"


namespace Engine
{
	Model::Model()
	{

	}

	Model::~Model()
	{
		for (auto& mesh : m_meshes)
		{
			delete mesh;
		}

		delete m_aabb;
	}

	AABB* Model::getAABB()
	{
		if (m_aabb == nullptr)
		{
			calculateAABB();
		}

		return m_aabb;
	}

	void Model::calculateAABB()
	{
		if (m_meshes.size())
		{
			for (const auto& mesh : m_meshes)
			{
				mesh->calculateAABB();
			}
			
			AABB* model_aabb = new AABB();
			AABB* mesh_aabb = m_meshes[0]->getAABB();
			model_aabb->points[0] = mesh_aabb->points[0];
			model_aabb->points[1] = mesh_aabb->points[1];
			

			for (int i = 1; i < m_meshes.size(); i++)
			{
				mesh_aabb = m_meshes[i]->getAABB();

				if (model_aabb->points[0].x < mesh_aabb->points[0].x) model_aabb->points[0].x = mesh_aabb->points[0].x;
				if (model_aabb->points[0].y < mesh_aabb->points[0].y) model_aabb->points[0].y = mesh_aabb->points[0].y;
				if (model_aabb->points[0].z < mesh_aabb->points[0].z) model_aabb->points[0].z = mesh_aabb->points[0].z;

				if (model_aabb->points[1].x > mesh_aabb->points[1].x) model_aabb->points[1].x = mesh_aabb->points[1].x;
				if (model_aabb->points[1].y > mesh_aabb->points[1].y) model_aabb->points[1].y = mesh_aabb->points[1].y;
				if (model_aabb->points[1].z > mesh_aabb->points[1].z) model_aabb->points[1].z = mesh_aabb->points[1].z;
			}

			m_aabb = model_aabb;
		}
	}



	void Model::startAnimation(std::string key)
	{
		for (auto& mesh : m_meshes)
		{
			mesh->startAnimation(key);
		}
	}
}
