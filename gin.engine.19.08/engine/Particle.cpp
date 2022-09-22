#include "pch.h"
#include "Particle.h"

namespace Engine
{
	Particle::Particle() 
		: counter(0),
		m_position(Vector3(0, 0, 0)), 
		m_scale(Vector3(1, 1, 1)), 
		m_rect(Vector4(-1, 1, 1, -1)) 
	{

	}
	
	Vector3 Particle::getPosition() 
	{
		return m_position; 
	}
	
	Vector3 Particle::getScale() 
	{ 
		return m_scale; 
	}

	Vector4 Particle::getRect() 
	{
		return m_rect;
	}
}