#pragma once

#include "IVertexData.h"

namespace Engine
{
	class VertexDataHelper
	{
	public:
		static void FillColor(IVertexData* vd, Vector4 color);
	};
}

