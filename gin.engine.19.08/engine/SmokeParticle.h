#pragma once

#include "Particle.h"

namespace Engine
{

	class SmokeParticle : public Particle
	{
	private:
		Vector3 direction;
		float scalefactor;
		float speed;
	public:
		SmokeParticle();
		void update();
	};

}



