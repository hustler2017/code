#pragma once


#include "Common.h"

namespace Engine
{
	class Helper
	{
	public:
		static bool contain(Area& area, Vector2& pos);
		static double distance(Vector2 a, Vector2 b);
		static double distance(Vector3 a, Vector3 b);
		static void normalize(float& x, float& y);
	};


}
