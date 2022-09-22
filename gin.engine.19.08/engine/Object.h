#pragma once
#include "pch.h"
#include "Common.h"
#include "Model.h"
#include <string>

namespace Engine
{
	enum ObjectType
	{
		OBJECT,
		TREE,
		AGENT
	};


	class Object
	{
	protected:
		Model* m_pModel;
		Position m_position;
		std::string m_name;
		ObjectType type;
	public:
		
		bool selectable;
		bool visible;

		Object(Model* model);
		Object() : m_pModel(nullptr) {};
		~Object();

		void setName(std::string name);
		std::string getName();

		void setModel(Model* m);
		Model* getModel();

		virtual Position* getPosition();
		ObjectType getType()
		{
			return type;
		}


	};
}
