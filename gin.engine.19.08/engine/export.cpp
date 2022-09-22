#include "pch.h"
#include "Direct3D.h"
#include "dllexport.h"

Graphics::Direct3D* createInstance(HWND hWnd)
{
	return new Graphics::Direct3D(hWnd);
}


void render(Graphics::Direct3D* d3d)
{
	d3d->clear();
	d3d->present();
}


void clearInstance(Graphics::Direct3D* d3d)
{
	delete d3d;
}