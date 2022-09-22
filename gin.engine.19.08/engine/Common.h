#pragma once
#include "pch.h"
#include <math.h>

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(x) if(x) { x->Release(); x = nullptr; }
#endif

namespace Engine
{

	struct Area
	{
		float left;
		float top;
		float right;
		float bottom;
	};

	struct Vector2
	{
		float x;
		float y;

		Vector2(float x_, float y_) : x(x_), y(y_) {}
		Vector2() : x(0), y(0) {}

		bool operator==(const Vector2& pOther)
		{
			return (fabs(x) - fabs(pOther.x)) < 0.005f && (fabs(y) - fabs(pOther.y)) < 0.005f;
		}
	};

	struct Vector3
	{
		float x;
		float y;
		float z;

		Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
		Vector3() :x(0), y(0), z(0) {}

		bool operator==(const Vector3& pOther)
		{
			return (fabs(x) - fabs(pOther.x)) < 0.005f 
				&& (fabs(y) - fabs(pOther.y)) < 0.005f
				&& (fabs(z) - fabs(pOther.z)) < 0.005f;
		}

		Vector3 operator+(const Vector3& other)
		{
			return Vector3(x + other.x, y + other.y, z + other.z);
		}

		Vector3& operator+=(const Vector3& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}
	};

	struct Vector4
	{
		float x;
		float y;
		float z;
		float w;

		Vector4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
		Vector4() : x(0), y(0), z(0), w(0) {}
	};


	struct Position
	{
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;


		Position()
		{
			position = { 0,0,0 };
			rotation = {0,0,0};
			scale = {1,1,1};
		}
	};
}