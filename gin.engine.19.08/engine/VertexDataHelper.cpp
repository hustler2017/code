#include "pch.h"
#include "VertexDataHelper.h"


namespace Engine
{
	void VertexDataHelper::FillColor(IVertexData* vd, Vector4 color)
	{
		int count = vd->getColorCount();

		if (count == 0)
		{
			count = vd->getCoordinatesCount();
			vd->setColorCount(count);
			
		}

		for (int i = 0; i < count; i++)
		{
			vd->setColor(i, color);
		}
	}
}