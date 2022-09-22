#pragma once
#include "Mesh.h"
#include <vector>
#include <string>

namespace Engine
{
	class Terrain : public Mesh
	{
		Vector2 m_tiling[5];
		Vector2 m_size;
		bool m_need_update;
	public:
		
		Terrain();
		~Terrain();

		void calculateSize();
		void updateUVChannel(int channel);

		Vector2 getTiling(int channel);
		void setTiling(int channel, Vector2 tiling);
		void init();
	};
}
