#pragma once

#include "Common.h"
#include "Direct3D.h"

namespace Engine
{
	class Sprite
	{
	public:
		Vector4 rect;
		ID3D11ShaderResourceView* texture;
	};

	class Sprite3D : public Sprite
	{
	public:
		Vector3 position;
		Vector3 scale;
	};
}

