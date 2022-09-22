#include "GameField.h"
#include "GameObjects.h"
#include <sstream>
#include <dwrite.h>

extern IDWriteTextFormat* m_pTextFormat;
extern ID2D1SolidColorBrush* pBrushPuck;

GameField::GameField()
	: x(-300), y(500), width(600), height(1000)
{
	float goalDepth = 50.;
	float goalWidth = 150.;
	float borderThickness = 40.;

	pDefConfig = new btDefaultCollisionConfiguration();
	pDispather = new btCollisionDispatcher(pDefConfig);
	overlappingPairCache = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver;
	dynamicsWorld = new btDiscreteDynamicsWorld(pDispather, overlappingPairCache, solver, pDefConfig);
	dynamicsWorld->getDispatchInfo().m_useContinuous = true;
	dynamicsWorld->setGravity(btVector3(0, 0, 0));

	// left border
	{
		float x1 = x;
		float y1 = y - height + goalDepth;
		float x2 = x1 + borderThickness;
		float y2 = y - goalDepth;

		addObject(new GameBorder(x1, y1, x2, y2));
	}

	// right border
	{
		float x1 = x + width - borderThickness;
		float y1 = y - height + goalDepth;
		float x2 = x1 + borderThickness;
		float y2 = y - goalDepth;

		addObject(new GameBorder(x1, y1, x2, y2));
	}
	
	// top goal top border
	{
		float x1 = x + (width - goalWidth) / 2 - borderThickness;
		float y1 = y;
		float x2 = x1 + goalWidth + 2* borderThickness;
		float y2 = y - borderThickness;

		addObject(new GameBorder(x2, y2, x1, y1));
	}

	// bottom goal bottom border
	{
		float x1 = x + (width - goalWidth) / 2 - borderThickness;
		float y1 = y - height;
		float x2 = x1 + goalWidth + 2 * borderThickness;
		float y2 = y1 + borderThickness;

		addObject(new GameBorder(x1, y1, x2, y2));
	}

	// top goal left border
	{
		float x1 = x + (width - goalWidth) / 2 - borderThickness;
		float y1 = y - borderThickness;
		float x2 = x1 + borderThickness;
		float y2 = y1 - goalDepth;

		addObject(new GameBorder(x1, y1, x2, y2));
	}

	// bottom goal left border
	{
		float x1 = x + (width - goalWidth) / 2 - borderThickness;
		float y1 = y - height + borderThickness;
		float x2 = x1 + borderThickness;
		float y2 = y1 + goalDepth;

		addObject(new GameBorder(x1, y1, x2, y2));
	}

	// top goal right border
	{
		float x1 = x + width - (width - goalWidth) / 2;
		float y1 = y - borderThickness;
		float x2 = x1 + borderThickness;
		float y2 = y1 - goalDepth;

		addObject(new GameBorder(x1, y1, x2, y2));
	}

	// bottom goal right border
	{
		float x1 = x + width - (width - goalWidth) / 2;
		float y1 = y - height + borderThickness + goalDepth;
		float x2 = x1 + borderThickness;
		float y2 = y1 - goalDepth;

		addObject(new GameBorder(x1, y1, x2, y2));
	}


	// top left border
	{
		float x1 = x + borderThickness;
		float y1 = y - goalDepth;
		float x2 = x + (width - goalWidth) / 2 - borderThickness;
		float y2 = y1 - borderThickness;

		addObject(new GameBorder(x1, y1, x2, y2));
	}

	// bottom left border
	{
		float x1 = x + borderThickness;
		float y1 = y - height + goalDepth;
		float x2 = x + (width - goalWidth) / 2 - borderThickness;
		float y2 = y1 + borderThickness;

		addObject(new GameBorder(x1, y1, x2, y2));
	}

	// bottom right border
	{
		float x1 = x + width - borderThickness;
		float y1 = y - height + goalDepth;
		float x2 = x + width - (width - goalWidth) / 2 + borderThickness;
		float y2 = y1 + borderThickness;

		addObject(new GameBorder(x1, y1, x2, y2));
	}
	// top right border
	{
		float x1 = x + width - borderThickness;
		float y1 = y - goalDepth;
		float x2 = x + width - (width - goalWidth) / 2 + borderThickness;
		float y2 = y1 - borderThickness;

		addObject(new GameBorder(x1, y1, x2, y2));
	}

	auto gp = new GamePuck(0, 0, 20);
	gp->pRigidBody->setLinearVelocity({ 0.3,0.5,0 });
	addObject(gp);
	
	gb = new GameBat(-100, 100, 10,30);
	addObject(gb);

	
}


GameField::~GameField()
{
	
	for (int j = 0; j < objects.size(); j++)
	{
		dynamicsWorld->removeCollisionObject(objects[j]->pRigidBody);
		delete objects[j];
	}

	objects.clear();

	delete dynamicsWorld;
	delete solver;
	delete overlappingPairCache;
	delete pDispather;
	delete pDefConfig;
}


void GameField::addObject(GameObject* pObj)
{
	dynamicsWorld->addRigidBody(pObj->pRigidBody);
	objects.push_back(pObj);
}


void GameField::update()
{
	dynamicsWorld->stepSimulation(1.f / 60.0f);
	for (auto it = objects.begin(); it < objects.end(); it++)
		(*it)->update();
}

void GameField::updateState(int _dx, int _dy)
{
	gb->pRigidBody->setLinearVelocity(btVector3(_dx, _dy, 0));
}

void GameField::draw()
{
	for (auto it = objects.begin(); it < objects.end(); it++)
	{
		(*it)->draw();
	}

	std::wstring str = L"dx = " + std::to_wstring(dx) + L" ; dy = " + std::to_wstring(dy);
	const WCHAR* s = str.c_str();
	pRenderTarget->DrawTextW(s, wcslen(s), m_pTextFormat, D2D1::RectF(-600, 500, 3000, 2000), pBrushPuck);

}




