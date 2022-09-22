#include "GameBorder.h"

extern ID2D1SolidColorBrush* pBrushBorders;

GameBorder::GameBorder(float x1, float y1, float x2, float y2)
	:x1(x1), y1(y1), x2(x2), y2(y2)
{
	float sizeVX = abs(x2 - x1) / 2;
	float sizeVY = abs(y2 - y1) / 2;
	float posX = (x2 + x1) / 2;
	float posY = (y1 + y2) / 2;

	pCollisionShape = new btBoxShape(btVector3(sizeVX / 100, sizeVY / 100, 10.0f));

	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(posX / 100, posY / 100, 0));
	btScalar mass(0.);
	btVector3 localInertia(0, 0, 0);

	pMotionState = new btDefaultMotionState(transform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, pMotionState, pCollisionShape, localInertia);
	rbInfo.m_restitution = 1.0;
	pRigidBody = new btRigidBody(rbInfo);
	pRigidBody->setFriction(btScalar(0.0f));
}

void GameBorder::draw()
{
	pRenderTarget->DrawRectangle(D2D1::RectF(x1, y1, x2, y2), pBrushBorders, 1.0f);
}


void GameBorder::update()
{
	btTransform trans;
	pRigidBody->getMotionState()->getWorldTransform(trans);
	float x = trans.getOrigin().getX() * 100.;
	float y = trans.getOrigin().getY() * 100.;
}
