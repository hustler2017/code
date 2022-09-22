#include "pch.h"
#include <assert.h>
#include "ManipulatorAxis.h"
#include "FBXModelLoader.h"
#include "PositionsBuffer.h"
#include "VertexDataHelper.h"

namespace Engine
{
	ManipulatorAxis::ManipulatorAxis(std::wstring modelFilename, Picker* picker)
		: m_target_obj(nullptr), m_picker(picker)
	{
		m_pModel = new Model();
		FBXModelLoader::load(m_pModel, modelFilename);
		m_pModel->calculateAABB();


		Vector4 colors[] = {
			Vector4(1,0,0,1),
			Vector4(0,1,0,1),
			Vector4(0,0,1,1),
			Vector4(1,1,0,1),
			Vector4(0,1,1,1),
			Vector4(1,0,1,1)
		};

		for (int i = 0; i < 6; i++)
		{
			IVertexData* vd = m_pModel->m_meshes[i]->getVertexData();
			vd->setColorCount( vd->getCoordinatesCount() );
			VertexDataHelper::FillColor(vd, colors[i]);
		}

		visible = false;
	}

	ManipulatorAxis::~ManipulatorAxis()
	{
		delete m_pModel;
	}

	void ManipulatorAxis::setTarget(Object* obj)
	{
		m_target_obj = obj;
		
		//visible = true;
	}

	Position* ManipulatorAxis::getPosition()
	{
		updatePosition();	
		return &m_position;
	}

	void ManipulatorAxis::updatePosition()
	{
		if (m_target_obj)
		{
			m_position.position = m_target_obj->getPosition()->position;
		}
	}

	ManipulatorAxis::ManipulatorElement ManipulatorAxis::checkPicking(int x, int y)
	{
		using namespace DirectX;

		XMVECTOR rayOrigin;
		XMVECTOR rayDirection;

		m_picker->getPickLine(x, y, rayOrigin, rayDirection);

		updatePosition();

		assert(m_pModel->m_meshes.size() == 6);

		if (m_picker->intersectAABB(m_pModel->m_meshes[0]->getAABB(), getPosition(), rayOrigin, rayDirection))
		{
			return ManipulatorElement::MOVE_X;
		}

		if (m_picker->intersectAABB(m_pModel->m_meshes[1]->getAABB(), getPosition(), rayOrigin, rayDirection))
		{
			return ManipulatorElement::MOVE_Y;
		}

		if (m_picker->intersectAABB(m_pModel->m_meshes[2]->getAABB(), getPosition(), rayOrigin, rayDirection))
		{
			return ManipulatorElement::MOVE_Z;
		}

		if (m_picker->intersectAABB(m_pModel->m_meshes[3]->getAABB(), getPosition(), rayOrigin, rayDirection))
		{
			return ManipulatorElement::ROT_Z;
		}

		if (m_picker->intersectAABB(m_pModel->m_meshes[4]->getAABB(), getPosition(), rayOrigin, rayDirection))
		{
			return ManipulatorElement::ROT_Y;
		}

		if (m_picker->intersectAABB(m_pModel->m_meshes[5]->getAABB(), getPosition(), rayOrigin, rayDirection))
		{
			return ManipulatorElement::ROT_X;
		}

		return ManipulatorElement::NONE;
	}

	void ManipulatorAxis::clearTarget()
	{
		m_target_obj = nullptr;
		visible = false;
	}
}