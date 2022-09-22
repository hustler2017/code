#pragma once
#include "Object.h"
#include "Sprite.h"
#include <vector>
#include "Model.h"

namespace Engine
{
	class Tree : public Object
	{
	public:

		std::vector<Sprite3D> sprites;

		Tree();
		~Tree();
	};
}
