#include "pch.h"
#include "Smoke.h"
#include "SmokeParticle.h"

namespace Engine
{
	Smoke::Smoke(ID3D11ShaderResourceView* texture, int lifetime, int born_interval, int max_particles) 
		: Particles(texture, lifetime, born_interval, max_particles)
	{
	}

	Particle* Smoke::createParticle()
	{
		return new SmokeParticle();
	}

}