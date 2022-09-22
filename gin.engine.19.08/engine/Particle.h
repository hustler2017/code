#pragma once

#include "Common.h"

namespace Engine
{
	class Particle
	{
	protected:
		Vector3 m_position;
		Vector3 m_scale;
		Vector4 m_rect;
	public:
		int counter;
		Particle();
		virtual ~Particle() {};
		Vector3 getPosition();
		Vector3 getScale();
		Vector4 getRect();
		virtual void update() = 0;
	};
}

