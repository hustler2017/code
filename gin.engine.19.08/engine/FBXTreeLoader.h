#pragma once

#include <string>
#include "Direct3D.h"
#include "Object.h"

namespace Engine
{
	class FBXTreeLoader
	{
	public:

		static void Load(std::wstring filename, std::list<Object*>* objects, std::map<int, Model*>* treeModels, Graphics::Direct3D* d3d);

	};
}

