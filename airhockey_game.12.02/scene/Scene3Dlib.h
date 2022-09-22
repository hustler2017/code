#pragma once
#include <Windows.h>
#include <string>

namespace Scene3D {

	using namespace std;

	class ILight {
	public:
		virtual void setPosition(float x, float y, float z) = 0;
		virtual void setIntensity(float i) = 0;
		virtual void setColor(float r, float g, float b) = 0;

	};

	class IModel {
	public:
		virtual void setPosition(float x, float y, float z) = 0;
		virtual void setRotation(float x, float y, float z) = 0;
		virtual void rotate(float x, float y, float z) = 0;
		virtual void move(float x, float y, float z) = 0;
		virtual ~IModel() {};
	};

	class IScene3D
	{
	public:
		//virtual IModel* CreateModel(const wstring filename) = 0;
		//virtual ILight* CreateLight() = 0;
		virtual void render() = 0;
		virtual ~IScene3D() {};
	};

	IScene3D* createScene3D(HWND hWnd);
}