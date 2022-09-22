#pragma once

#include "Particles.h"
#include "SpriteShader.h"

namespace Engine
{
	class ParticlesRenderer
	{
	protected:
		SpriteShader* m_shader;
	private:
		void addSprites(Particles* particles);
	public:
		ParticlesRenderer(SpriteShader* shader);
		~ParticlesRenderer();
		
		void render(Particles* particles);
		void render(std::list<Particles*>& particleObjects);
	};
}

