#pragma once
#include <vector>
#include <btBulletDynamicsCommon.h>
#include "GameObjects.h"

class GameField
{
	float x;
	float y;
	float width;
	float height;


	float dx, dy;

	btDefaultCollisionConfiguration* pDefConfig;
	btCollisionDispatcher* pDispather;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;

	std::vector<GameObject*> objects;
	void addObject(GameObject* pObj);

public:
	GameBat* gb;

	GameField();
	//GameField(float x, float y, float w, float h);
	~GameField();
	void draw();
	void update();
	void updateState(int dx, int dy);

	
};
