#pragma once

namespace Engine
{
	namespace Navigation
	{
		class FunnelAlgorithm
		{
		public:
			static void Search(float* start, float* end, float* points, int* portals, int num_portals, float* path, int& path_size);
		};
	}
}
