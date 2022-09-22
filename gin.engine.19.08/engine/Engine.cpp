#include "pch.h"
#include "Engine.h"
#include "FBXModelLoader.h"
#include "FBXMeshLoader.h"
#include "FBXTreeLoader.h"
#include "CommonController.h"
#include "CameraTurnController.h"
#include "IdleBehaviour.h"
#include "AgentMove.h"
#include "AgentStay.h"
#include "MeshNavigation.h"
#include "IEngineSettings.h"
#include "Picker.h"
#include "VertexDataHelper.h"
#include "CommandMove.h"

namespace Engine
{
	Engine::Engine(IEngineSettings* settings) 
		: m_settings(settings), world_update(false)
	{
		m_renderer = new Renderer(
			new Graphics::Direct3D(m_settings->getHWnd()),
			m_settings,
			&m_models,
			&m_objects,
			&m_agents,
			&m_terrain
		);

		createTerrain();
		createNavigationMesh();
		createNavigation();
		loadTrees();
	}

	int Engine::checkManipulatorPick(float x, float y)
	{
		return m_renderer->getManipulator()->checkPicking(x, y);
	}

	void Engine::createTerrain()
	{
		m_terrain = new Terrain;
		FBXMeshLoader::load(m_terrain, m_settings->getPath(L"models") + L"terrain.fbx");
		
		m_terrain->init();

		m_terrain->addTexture(m_settings->getPath(L"textures") + L"grass05.png");
		m_terrain->setTiling(0, Vector2(200.0f, 200.0f));

		m_terrain->addTexture(m_settings->getPath(L"textures") + L"grass06.png");
		m_terrain->setTiling(1, Vector2(200.0f, 200.0f));

		m_terrain->addTexture(m_settings->getPath(L"textures") + L"dust02.png");
		m_terrain->setTiling(2, Vector2(200.0f, 200.0f));

		m_terrain->addTexture(m_settings->getPath(L"textures") + L"dust06.png");
		m_terrain->setTiling(3, Vector2(200.0f, 200.0f));

		m_terrain->addTexture(m_settings->getPath(L"textures") + L"mask.png");
		m_terrain->setTiling(4, Vector2(1.0f, 1.0f));

		m_terrain->setShader(m_renderer->m_terrainShader);
	}

	void Engine::loadTerrain(Terrain* pTerrain, std::wstring filename)
	{
		FBXMeshLoader::load(pTerrain, filename);

		pTerrain->init();

		pTerrain->addTexture(m_settings->getPath(L"textures") + L"grass02.png");
		pTerrain->addTexture(m_settings->getPath(L"textures") + L"grass03.png");
		pTerrain->addTexture(m_settings->getPath(L"textures") + L"dust02.png");
		pTerrain->addTexture(m_settings->getPath(L"textures") + L"dust06.png");
		pTerrain->addTexture(m_settings->getPath(L"textures") + L"mask.png");
	}

	Object* Engine::getPickedObject(float x, float y)
	{
		return m_renderer->getPicker()->getPickedObject(&m_objects, x, y);
	}

	Agent* Engine::getPickedAgent(float x, float y)
	{
		return m_renderer->getPicker()->getPickedAgent(&m_agents, x, y);
	}

	void Engine::clearAgents()
	{
		for (auto& obj : m_agents)
		{
			delete obj;
		}
	}
	
	void Engine::clearObjects()
	{
		for (auto& obj : m_objects)
		{
			delete obj;
		}
	}

	void Engine::clearModels()
	{
		for (auto& model : m_models)
		{
			delete model;
		}
	}

	Engine::~Engine()
	{
		clearAgents();
		clearObjects();
		clearModels();
	
		if(m_terrain) delete m_terrain;
		if(m_navmesh) delete m_navmesh;
		if(m_navigation) delete m_navigation;
		
		delete m_renderer;
	}

	void Engine::update()
	{
		if (world_update)
		{
			m_renderer->onEngineUpdate();

			for (auto& agent : m_agents)
			{
				agent->update();
			}
		}
	}

	void Engine::render()
	{
		update();
		m_renderer->clear();
		m_renderer->render();
		m_renderer->present();
	}

	void Engine::createNavigation()
	{
		Navigation::MeshNavigation* n = new Navigation::MeshNavigation(m_navmesh->getVertexData(), &m_renderer->debugLiner);
		n->fillNodeLinks(&m_renderer->nodeLines);

		m_navigation = n;
	}

	void Engine::createNavigationMesh()
	{
		m_navmesh = new Mesh;
		FBXMeshLoader::load(m_navmesh, m_settings->getPath(L"models") + L"navmesh.fbx");
		VertexDataHelper::FillColor(m_navmesh->getVertexData(), Vector4(0,0,1,0.2f));
		m_navmesh->setShader(m_renderer->m_colorShader);
		VertexDataHelper::FillColor(m_navmesh->getVertexData(), Vector4(0, 0, 1, 1.0f));
		m_navmesh->setShader(m_renderer->m_linesShader);
		m_renderer->m_navmesh = m_navmesh;
	}


	Agent* Engine::createAgent()
	{
		agentModel = new Model();
		FBXModelLoader::load(agentModel, m_settings->getPath(L"models") + L"soldier.fbx");
		MeshAnimation* animation = FBXMeshLoader::loadAnimation(m_settings->getPath(L"models") + L"soldier.fbx");
		agentModel->m_meshes[0]->addAnimation("walk", animation);
		agentModel->setShader(m_renderer->m_animatedMeshShader);
		m_models.push_back(agentModel);

		Agent* agent = new Agent();
		agent->setModel(agentModel);
		AgentBehaviourContext* agentContext = new AgentBehaviourContext(agent, m_navigation, &m_renderer->debugLiner);
		agent->addTask(new AgentMove(agentContext));
		agent->addTask(new AgentStay(agentContext));
		agent->setDefaultTask("stay");
		m_agents.push_back(agent);

		return agent;
	}


	Model* Engine::loadModel(std::wstring filename)
	{
		Model* model = new Model();
		FBXModelLoader::load(model, filename);

		for (auto& mesh : model->m_meshes)
		{
			if (mesh->getCurrentAnimation())
			{
				mesh->setShader(m_renderer->m_animatedMeshShader);
			}
			else
			{
				mesh->setShader(m_renderer->m_staticMeshShader);
			}
		}

		model->calculateAABB();
		m_models.push_back(model);
		return model;
	}

	bool Engine::loadAnimation(Mesh* mesh, std::wstring filename, std::string name)
	{
		MeshAnimation* animation = FBXMeshLoader::loadAnimation(filename);
		if (animation) mesh->addAnimation(name, animation);
		return true;
	}


	Object* Engine::createObject(Model* model)
	{
		Object* obj = new Object(model);
		obj->setName("asdas");
		obj->visible = true;
		m_objects.push_back(obj);
		return obj;
	}

	void Engine::removeObject(Object* obj)
	{
		auto it = std::find(m_objects.begin(), m_objects.end(), obj);
		if (it != m_objects.end()) {
			m_objects.remove(obj);
			delete obj;
		}
	}

	void Engine::loadTrees()
	{
		std::map<int, Model*> treeModels;
		FBXTreeLoader::Load(m_settings->getPath(L"models") + L"trees.fbx", &m_objects, &treeModels, m_renderer->m_d3d);
		for (auto& model : treeModels)
		{
			model.second->setShader(m_renderer->m_staticMeshShader);
		}
	}

	void Engine::removeModel(Model* model)
	{
		/*
		auto it = std::find(m_models.begin(), m_models.end(), model);
		if (it != m_models.end()) {

			delete model;
		}
		*/
	}

	ManipulatorAxis* Engine::getManipulator()
	{
		return m_renderer->getManipulator();
	}

	Axis* Engine::getAxis()
	{
		return m_renderer->getAxis();
	}

	Grid* Engine::getGrid()
	{
		return m_renderer->getGrid();
	}

	void Engine::start()
	{
		world_update = true;
	}

	void Engine::stop()
	{
		world_update = false;
	}

	Camera* Engine::getCamera()
	{
		return m_renderer->getCamera();
	}

	Light* Engine::getLight()
	{
		return m_renderer->getLight();
	}

	Terrain* Engine::getTerrain()
	{
		return m_terrain;
	}

	void Engine::commandMove(Agent* agent, int x, int y)
	{
		float xi; 
		float yi;
		OutputDebugStringA("\ntry pick terrain...");
		if (m_renderer->getPicker()->getPickedMesh(m_navmesh, Position(), x, y, xi, yi))
		{
			OutputDebugStringA("\nterrain picked...");
			agent->setCommand(new CommandMove(xi, yi));
		}
	}
}
