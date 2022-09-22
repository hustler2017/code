#pragma once
#include "Particles.h"

namespace Engine
{
	class Smoke : public Particles
	{
	protected:
		Particle* createParticle();
	public:
		Smoke(ID3D11ShaderResourceView* texture, int lifetime, int born_interval, int max_particles);
	};
	
}

