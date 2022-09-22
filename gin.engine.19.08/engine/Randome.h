#pragma once

#include <vector>

namespace Engine {

	class Randome
	{
		static std::vector<float> numbers;
		static int i;

	public:
		static float rand();
	};
}

