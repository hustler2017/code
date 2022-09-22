#include "pch.h"
#include "Axis.h"

namespace Engine
{
	Axis::Axis()
	{
		Mesh* mesh = new Mesh();
		IVertexData* vdata = mesh->getVertexData();
		vdata->setCoordinatesCount(6);
		vdata->setColorCount(6);
		vdata->setCoordinates(0, Vector3(0, 0, 0));
		vdata->setColor(0, Vector4(1, 0, 0, 1));
		vdata->setCoordinates(1, Vector3(1, 0, 0));
		vdata->setColor(1, Vector4(1, 0, 0, 1));
		vdata->setCoordinates(2, Vector3(0, 0, 0));
		vdata->setColor(2, Vector4(0, 1, 0, 1));
		vdata->setCoordinates(3, Vector3(0, 1, 0));
		vdata->setColor(3, Vector4(0, 1, 0, 1));
		vdata->setCoordinates(4, Vector3(0, 0, 0));
		vdata->setColor(4, Vector4(0, 0, 1, 1));
		vdata->setCoordinates(5, Vector3(0, 0, 1));
		vdata->setColor(5, Vector4(0, 0, 1, 1));

		m_pModel = new Model();
		m_pModel->m_meshes.push_back(mesh);

		visible = true;
	}

	Axis::~Axis()
	{
		delete m_pModel;
	}

	void Axis::setVisible(bool status)
	{
		visible = status;
	}

	bool Axis::getVisible()
	{
		return visible;
	}
}