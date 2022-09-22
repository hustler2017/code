#include "pch.h"

#include "SmokeParticle.h"
#include "Randome.h"




namespace Engine
{

	SmokeParticle::SmokeParticle()
	{
		
		speed = 0.1f + 0.1f * Randome::rand();
		scalefactor = Randome::rand() * 0.2f;
		direction.x = Randome::rand() - 0.5f;
		direction.y = Randome::rand() - 0.5f;
		direction.z = 1.0f;
	}

	void SmokeParticle::update()
	{
		speed *= 0.998f;
		scalefactor *= 0.998f;

		m_position.x += direction.x * speed;
		m_position.y += direction.y * speed;
		m_position.z += direction.z * speed;
		m_scale.x += scalefactor;
		m_scale.y += scalefactor;
		m_scale.z += scalefactor;

		m_position.x += m_position.z * 0.001f;
	}


}
