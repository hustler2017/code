#pragma once
#include "pch.h"
#include "Object.h"


namespace Engine
{
	class Grid : public Object
	{
	private:
		float size;
		float density;

	public:
		Grid();
		~Grid();

		void setDensity(float density);
		void setSize(float size);

		float getDensity();
		float getSize();

	};


}