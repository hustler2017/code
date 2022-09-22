#include "GameBat.h"


extern ID2D1SolidColorBrush* pBrushBatDown;
extern ID2D1SolidColorBrush* pBrushBatUp;

GameBat::GameBat(float x, float y, float r1, float r2)
	: x(x), y(y), r1(r1), r2(r2)
{
	btCollisionShape* pCollisionShape = new btSphereShape(btScalar(r2/100));
	btTransform startTransform;
	startTransform.setIdentity();
	btScalar mass(1.f);
	btVector3 localInertia(0, 0, 0);
	startTransform.setOrigin(btVector3(btScalar(x/100), btScalar(y/100), 0));
	btDefaultMotionState* pMotionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, pMotionState, pCollisionShape, localInertia);
	rbInfo.m_restitution = 1.0;
	pRigidBody = new btRigidBody(rbInfo);
	pRigidBody->setFriction(btScalar(0.0f));
	pRigidBody->setLinearFactor(btVector3(1.0f, 1.0f, 0.0f));
	//pRigidBody->setCollisionFlags(pRigidBody->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
	pRigidBody->setActivationState(DISABLE_DEACTIVATION);
	pRigidBody->setCcdMotionThreshold(r2 / 100);
	pRigidBody->setCcdSweptSphereRadius(r2 / 100);

}


void GameBat::draw()
{
	pRenderTarget->FillEllipse(
		D2D1::Ellipse(
			D2D1::Point2F(x, y),
			r2,
			r2
		),
		pBrushBatDown
	);

	pRenderTarget->FillEllipse(
		D2D1::Ellipse(
			D2D1::Point2F(x, y),
			r1,
			r1
		),
		pBrushBatUp
	);
}

void GameBat::update()
{
	btTransform trans;
	pRigidBody->getMotionState()->getWorldTransform(trans);
	x = trans.getOrigin().getX() * 100.0f;
	y = trans.getOrigin().getY() * 100.0f;
	float z = trans.getOrigin().getZ() * 100.0f;

	if (z != 0)
	{
		int a = 1;
	}

	

}

