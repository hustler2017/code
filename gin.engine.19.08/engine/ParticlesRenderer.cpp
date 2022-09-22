#include "pch.h"
#include "ParticlesRenderer.h"

namespace Engine
{
	ParticlesRenderer::ParticlesRenderer(SpriteShader* shader)
		: m_shader(shader)
	{

	}

	ParticlesRenderer::~ParticlesRenderer()
	{

	}

	void ParticlesRenderer::addSprites(Particles* particles)
	{
		std::list<Particle*>* particleList = particles->getParticles();
		ID3D11ShaderResourceView* texture = particles->getTexture();

		for (auto& particle : *particleList)
		{
			Vector3 position = particle->getPosition();
			Vector3 scale = particle->getScale();
			Vector4 rect = particle->getRect();
			rect.x *= scale.x;
			rect.y *= scale.y;
			rect.z *= scale.x;
			rect.w *= scale.y;

			m_shader->addSprite(rect, position, texture);
		}
	}

	void ParticlesRenderer::render(Particles* particles)
	{
		if (particles->getParticles()->size())
		{
			addSprites(particles);
			m_shader->render();
			m_shader->clear();
		}
		
	}

	void ParticlesRenderer::render(std::list<Particles*>& particleObjects)
	{

		for (auto& obj : particleObjects)
		{
			addSprites(obj);
		}

		m_shader->render();
		m_shader->clear();
	}
}