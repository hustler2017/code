#pragma once
#include "pch.h"
#include "Common.h"

namespace Engine
{
	class AABB
	{
	public:

		Vector3 points[2];

		AABB()
		{
			points[0] = Vector3(0, 0, 0);
			points[1] = Vector3(0, 0, 0);
		}
	};
}



