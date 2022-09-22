#pragma once
#include "pch.h"
#include <string>
#include <vector>
#include <map>
#include <list>
#include "EngineSettings.h"
#include "Renderer.h"
#include "Terrain.h"
#include "Agent.h"
#include "INavigation.h"
#include "ManipulatorAxis.h"


namespace Engine
{
	class Engine
	{
	private:
		IEngineSettings* m_settings;

		std::list<Model*> m_models;
		std::list<Object*> m_objects;
		std::list<Agent*> m_agents;

		Renderer* m_renderer;

		Navigation::INavigation* m_navigation;

		Terrain* m_terrain;
		Mesh* m_navmesh;
		Model* agentModel;

		bool world_update;

	private:
		void clearObjects();
		void clearModels();
		void clearAgents();
		
		void createTerrain();
		void createNavigation();
		void createNavigationMesh();

	public:

		Engine(IEngineSettings* settings);
		~Engine();

		void render();
		void update();
		
		Object* createObject(Model* model);
		void removeObject(Object* obj);

		Agent* createAgent();

		Camera* getCamera();
		Light* getLight();
		
		void loadTerrain(Terrain* pTerrain, std::wstring filename);
		Terrain* getTerrain();

		Model* loadModel(std::wstring filename);
		void removeModel(Model* model);

		bool loadAnimation(Mesh* mesh, std::wstring filename, std::string name);
		
		Object* getPickedObject(float x, float y);
		Agent* getPickedAgent(float x, float y);
		int checkManipulatorPick(float x, float y);
		ManipulatorAxis* getManipulator();
		Axis* getAxis();
		Grid* getGrid();

		void start();
		void stop();


		void loadTrees();

		void commandMove(Agent* agent, int x, int y);
	};

}


