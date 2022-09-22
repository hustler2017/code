#include "pch.h"
#include "Camera.h"



namespace Scene3D
{
	Camera::Camera()
	{
		aspectRatio = static_cast<float>(1920) / 1080;
		position = { 100. ,100. ,100. };
		target = { 0. ,0. ,0. };
	}

	void Camera::updateMatrix()
	{
		XMVECTOR vecCameraPosition = XMVectorSet(position.x, position.y, position.z, 1.0f);
		XMVECTOR vecCameraTarget = XMVectorSet(target.x, target.y, target.z);
		XMVECTOR vecUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
		XMMATRIX mxView = XMMatrixLookAtLH(vecCameraPosition, vecCameraTarget, vecUp);
		XMMATRIX mxPerspective = XMMatrixPerspectiveFovLH(0.25f * XM_PI, aspectRatio, 10.0f, 100.0f);
		
		mx = mxView * mxPerspective;
	}

	void Camera::setTarget(float x, float y, float z)
	{
		target.x = x;
		target.y = y;
		target.z = z;

		updateMatrix();
	}



	void Camera::setPosition(float x, float y, float z)
	{
		position.x = x;
		position.y = y;
		position.z = z;

		updateMatrix();
	}
}