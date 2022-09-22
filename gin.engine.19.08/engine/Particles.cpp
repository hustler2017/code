#include "pch.h"
#include "Particles.h"


namespace Engine
{
	Particles::Particles(ID3D11ShaderResourceView* texture, int lifetime, int born_interval, int max_particles)
		: m_lifetime(lifetime), m_texture(texture), m_born_interval(born_interval), m_born_counter(0), m_max_particles(max_particles)
	{

	}

	Particles::~Particles()
	{
		for (auto& particle : m_particles)
		{
			delete particle;
		}
	}

	void Particles::setLifetime(int time)
	{
		m_lifetime = time;
	}

	int Particles::getLifetime()
	{
		return m_lifetime;
	}



	void Particles::update()
	{


		if (m_born_counter++ > m_born_interval)
		{
			m_born_counter = 0;

			if (m_particles.size() < m_max_particles)
			{
				Particle* p = createParticle();
				m_particles.push_back(p);
			}			
		}

		for (auto it = m_particles.begin(); it != m_particles.end(); it++)
		{
			Particle* particle = (*it);

			particle->update();

			if (particle->counter++ > m_lifetime)
			{
				delete particle;
				it = m_particles.erase(it);
			}
		}
	}

	std::list<Particle*>* Particles::getParticles()
	{
		return &m_particles;
	}

	ID3D11ShaderResourceView* Particles::getTexture()
	{ 
		return m_texture; 
	}

	void Particles::setParticlesMaxCount(int count)
	{
		m_max_particles = count;
	}

	int Particles::getParticlesMaxCount()
	{
		return m_max_particles;
	}

	void Particles::setBornInterval(int count)
	{
		m_born_interval = count;
	}

	int Particles::getBornInterval()
	{
		return m_born_interval;
	}
}

