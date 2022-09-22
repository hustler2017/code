#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "Common.h"
#include "Sprite2DShader.h"


namespace Engine
{
	class Cursor
	{

	public:
		int x;
		int y;
		int width;
		int height;

		ID3D11ShaderResourceView* texture;
		Sprite2DShader* pShader;

		void render()
		{
			pShader->clear();
			pShader->addSprite(x, y, x + width, y + height, texture);
			pShader->render();
		}
	};
}

