#include "pch.h"
#include "AABBRenderer.h"

namespace Engine
{
	AABBRenderer::AABBRenderer(LinesShader* sh)
	{
		m_mesh = new Mesh();
		
		m_mesh->getVertexData()->setCoordinatesCount(24);
		m_mesh->getVertexData()->setColorCount(24);

		for (int i = 0; i < 24; i++)
		{
			m_mesh->getVertexData()->setColor(i, Vector4(0, 1, 0, 1));
		}

		m_shader = sh;
		m_shader->createResources(m_mesh);
	}

	AABBRenderer::~AABBRenderer()
	{
		delete m_mesh;
	}

	void AABBRenderer::updateData(AABB* aabb)
	{
		IVertexData* vd = m_mesh->getVertexData();
		/*
		vd->setCoordinates(0, aabb->points[0]); // 1
		vd->setCoordinates(1, Vector3(aabb->points[1].x, aabb->points[0].y, aabb->points[0].z)); // 2
		vd->setCoordinates(1, Vector3(aabb->points[0].x, aabb->points[1].y, aabb->points[0].z)); // 3 
		vd->setCoordinates(1, Vector3(aabb->points[1].x, aabb->points[1].y, aabb->points[0].z)); // 4


		vd->setCoordinates(0, aabb->points[1]); // 5
		vd->setCoordinates(1, Vector3(aabb->points[0].x, aabb->points[1].y, aabb->points[1].z)); // 6
		vd->setCoordinates(1, Vector3(aabb->points[1].x, aabb->points[0].y, aabb->points[1].z)); // 7
		vd->setCoordinates(1, Vector3(aabb->points[0].x, aabb->points[0].y, aabb->points[1].z)); // 8
		*/

		vd->setCoordinates(0, aabb->points[0]); // 1
		vd->setCoordinates(1, Vector3(aabb->points[1].x, aabb->points[0].y, aabb->points[0].z)); // 2

		vd->setCoordinates(2, aabb->points[0]); // 1
		vd->setCoordinates(3, Vector3(aabb->points[0].x, aabb->points[1].y, aabb->points[0].z)); // 3 

		vd->setCoordinates(4, Vector3(aabb->points[1].x, aabb->points[0].y, aabb->points[0].z)); // 2
		vd->setCoordinates(5, Vector3(aabb->points[1].x, aabb->points[1].y, aabb->points[0].z)); // 4

		vd->setCoordinates(6, Vector3(aabb->points[0].x, aabb->points[1].y, aabb->points[0].z)); // 3 
		vd->setCoordinates(7, Vector3(aabb->points[1].x, aabb->points[1].y, aabb->points[0].z)); // 4

		vd->setCoordinates(8, aabb->points[1]); // 5
		vd->setCoordinates(9, Vector3(aabb->points[0].x, aabb->points[1].y, aabb->points[1].z)); // 6

		vd->setCoordinates(10, aabb->points[1]); // 5
		vd->setCoordinates(11, Vector3(aabb->points[1].x, aabb->points[0].y, aabb->points[1].z)); // 7

		vd->setCoordinates(12, Vector3(aabb->points[0].x, aabb->points[1].y, aabb->points[1].z)); // 6
		vd->setCoordinates(13, Vector3(aabb->points[0].x, aabb->points[0].y, aabb->points[1].z)); // 8

		vd->setCoordinates(14, Vector3(aabb->points[0].x, aabb->points[0].y, aabb->points[1].z)); // 8
		vd->setCoordinates(15, Vector3(aabb->points[1].x, aabb->points[0].y, aabb->points[1].z)); // 7

		vd->setCoordinates(16, aabb->points[0]); // 1
		vd->setCoordinates(17, Vector3(aabb->points[0].x, aabb->points[0].y, aabb->points[1].z)); // 8

		vd->setCoordinates(18, Vector3(aabb->points[0].x, aabb->points[1].y, aabb->points[0].z)); // 3
		vd->setCoordinates(19, Vector3(aabb->points[0].x, aabb->points[1].y, aabb->points[1].z)); // 6

		vd->setCoordinates(20, Vector3(aabb->points[1].x, aabb->points[0].y, aabb->points[0].z)); // 2
		vd->setCoordinates(21, Vector3(aabb->points[1].x, aabb->points[0].y, aabb->points[1].z)); // 7

		vd->setCoordinates(22, Vector3(aabb->points[1].x, aabb->points[1].y, aabb->points[0].z)); // 4
		vd->setCoordinates(23, aabb->points[1]); // 5

		m_mesh->updateResources();
	}

	void AABBRenderer::render(AABB* aabb)
	{
		updateData(aabb);
		m_shader->render(m_mesh);
	}
}