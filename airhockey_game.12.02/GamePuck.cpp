#include "GamePuck.h"


extern ID2D1SolidColorBrush* pBrushBatDown;

GamePuck::GamePuck(float x, float y, float radius)
	:x(x), y(y), radius(radius)
{
	btCollisionShape* pCollisionShape = new btSphereShape(btScalar(radius/100));
	btTransform startTransform;
	startTransform.setIdentity();
	btScalar mass(1.f);
	btVector3 localInertia(0, 0, 0);
	startTransform.setOrigin(btVector3(btScalar(x/100), btScalar(y/100), 0));
	btDefaultMotionState* pMotionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, pMotionState, pCollisionShape, localInertia);
	rbInfo.m_restitution = 0.99;
	pRigidBody = new btRigidBody(rbInfo);
	pRigidBody->setLinearFactor(btVector3(1.0f, 1.0f, 0.0f));
	pRigidBody->setFriction(btScalar(0.0f));
	pRigidBody->setCcdMotionThreshold(radius / 100);
	pRigidBody->setCcdSweptSphereRadius(radius / 100);
}

void GamePuck::draw()
{
	pRenderTarget->FillEllipse(
		D2D1::Ellipse(
			D2D1::Point2F(x, y),
			radius,
			radius
		),
		pBrushBatDown
	);
}

void GamePuck::update()
{
	btTransform trans;
	pRigidBody->getMotionState()->getWorldTransform(trans);
	x = trans.getOrigin().getX() * 100.;
	y = trans.getOrigin().getY() * 100.;
	btVector3 v = pRigidBody->getLinearVelocity();
	
}
