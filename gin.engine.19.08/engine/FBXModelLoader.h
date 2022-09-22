#pragma once
#include "pch.h"
#include "Model.h"
#include <string>

namespace Engine
{
	class FBXModelLoader
	{
	public:
		static Model* load(Model* model, std::wstring filename);
	};
}
