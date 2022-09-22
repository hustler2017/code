#include "pch.h"
#include "Randome.h"
#include <vector>
#include <cstdlib> 
#include <ctime>

namespace Engine
{
	int Randome::i = 0;
	std::vector<float> Randome::numbers;

	float Randome::rand()
	{
		if (numbers.size() == 0)
		{
			numbers.reserve(1000);
			std::srand(std::time(nullptr));
			for (int k = 0; k < 1000; k++)
			{
				numbers.push_back((double)std::rand() / RAND_MAX);
			}
		}

		if (i >= numbers.size()) i = 0;
		return numbers[i++];
	}
}