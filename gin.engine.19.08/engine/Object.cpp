#include "pch.h"
#include "Object.h"



namespace Engine
{
	
	Object::Object(Model* model)
		: m_pModel(model),
		selectable(false),
		visible(false)
	{
	}

	void Object::setModel(Model* m)
	{
		m_pModel = m;
	}

	Object::~Object() 
	{
	}

	Model* Object::getModel()
	{
		return m_pModel;
	}

	Position* Object::getPosition()
	{
		return &m_position;
	}

	void Object::setName(std::string name)
	{
		m_name = name;
	}

	std::string Object::getName()
	{
		return m_name;
	}

}
