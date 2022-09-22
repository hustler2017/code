#pragma once
#include "pch.h"
#include "Mesh.h"
#include "AABB.h"
#include <vector>


namespace Engine
{
	class Model
	{
		IMeshShader* m_shader;
		AABB* m_aabb;

	public:
		std::vector<Mesh*> m_meshes;
		

		Model();
		~Model();

		void calculateAABB();
		AABB* getAABB();

		void setShader(IMeshShader* shader)
		{
			m_shader = shader;

			for (auto& mesh : m_meshes)
			{
				mesh->setShader(shader);
			}
		}

		void startAnimation(std::string key);


	};
}
