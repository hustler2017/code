#include "pch.h"
#include "Helper.h"
#include <math.h>


namespace Engine
{
	double Helper::distance(Vector2 a, Vector2 b)
	{
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}

	double Helper::distance(Vector3 a, Vector3 b)
	{
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
	}

	void Helper::normalize(float& x, float& y)
	{
		double d = sqrt(x * x + y * y);
		x /= d;
		y /= d;
	}

	bool Helper::contain(Area& area, Vector2& pos)
	{
		return (pos.x < area.right&& pos.y < area.bottom&& pos.x > area.left&& pos.y > area.top);
	}
}
