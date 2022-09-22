#pragma once

#include "Particle.h"
#include "Direct3D.h"
#include <list>

namespace Engine
{
	class Particles
	{

	protected:
		std::list<Particle*> m_particles;
		int m_lifetime;
		int m_born_interval;
		int m_born_counter;
		int m_max_particles;
		ID3D11ShaderResourceView* m_texture;

		virtual Particle* createParticle() = 0;
	public:
		Particles(ID3D11ShaderResourceView* texture, int lifetime, int born_interval, int max_particles);
		~Particles();
		void setLifetime(int time);
		int getLifetime();
		
		void update();
		std::list<Particle*>* getParticles();
		ID3D11ShaderResourceView* getTexture();
		void setParticlesMaxCount(int count);
		int getParticlesMaxCount();
		void setBornInterval(int count);
		int getBornInterval();
	};
}

