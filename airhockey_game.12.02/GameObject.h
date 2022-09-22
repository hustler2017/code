#pragma once
#include "Common.h"
#include <d2d1.h>
#include <d2d1_1.h>
#include "btBulletDynamicsCommon.h"

extern ID2D1HwndRenderTarget* pRenderTarget;

class GameField;

class GameObject
{
	friend GameField;
protected:
	btRigidBody* pRigidBody = nullptr;
	btDefaultMotionState* pMotionState = nullptr;
	btCollisionShape* pCollisionShape = nullptr;
public:
	GameObject() {}
	virtual ~GameObject() {
		delete pMotionState;
		delete pRigidBody;
	}
	virtual void update() {}
	virtual void draw() {}
};
