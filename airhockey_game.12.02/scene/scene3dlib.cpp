// scene3dlib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "Scene3D.h"

using namespace Scene3D;

namespace Scene3D {

	IScene3D* createScene3D(HWND hWnd)
	{
		Scene3D* s = new Scene3D(hWnd);
		return s;
	}
}


