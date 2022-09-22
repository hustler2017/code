#include "pch.h"
#include "Renderer.h"
#include <DirectXMath.h>

#include "TerrainShaderResources.h"
#include "Agent.h"
#include "Tree.h"
#include "Helper.h"


namespace Engine
{
	Renderer::Renderer(
		Graphics::Direct3D* d3d,
		IEngineSettings* pSettings,
		std::list<Model*>* models,
		std::list<Object*>* objects,
		std::list<Agent*>* agents,
		Terrain** terrain
	)
		: m_d3d(d3d),
		m_pSettings(pSettings),
		m_models(models),
		m_objects(objects),
		m_agents(agents),
		m_terrain(terrain)
	{
		m_navmesh = nullptr;

		createShaders();
		createRenderers();
		createAxis();
		createGrid();
		createLight();
		createCamera();
		m_picker = new Picker(m_d3d, m_camera, &debugLiner);
		createPositionBuffer();
		createManipulator();

		smoke = new Smoke(m_d3d->createTexture(m_pSettings->getPath(L"textures") + L"sprite_test.png"), 2000, 10, 100);
	}

	Renderer::~Renderer()
	{
		delete m_linesShader;
		delete m_colorShader;
		delete m_staticMeshShader;
		delete m_terrainShader;
		delete m_animatedMeshShader;
		delete m_spriteShader;

		delete m_aabbRenderer;
		delete m_objectsRenderer;
		
		
		delete axis;
		delete grid;
		delete m_light;
		delete m_camera;
		delete m_positionsBuffer;
		delete m_manipulator;
		delete m_pSettings;
		delete m_picker;

		delete smoke;

		delete m_d3d;
	}

	void Renderer::onEngineUpdate()
	{
		smoke->update();
	}

	void Renderer::createAxis()
	{
		axis = new Axis();
		axis->getModel()->setShader(m_linesShader);
	}

	void Renderer::createGrid()
	{
		grid = new Grid();
		grid->getModel()->setShader(m_linesShader);
	}

	void Renderer::createManipulator()
	{
		m_manipulator = new ManipulatorAxis(m_pSettings->getPath(L"models") + L"transform_manipulator.fbx", m_picker);
		m_manipulator->getModel()->setShader(m_colorShader);
	}

	void Renderer::createShaders()
	{
		m_linesShader = new LinesShader(m_d3d, m_pSettings);
		m_colorShader = new ColorShader(m_d3d, m_pSettings);
		m_staticMeshShader = new StaticMeshShader(m_d3d, m_pSettings);
		m_terrainShader = new TerrainShader(m_d3d, m_pSettings);
		m_animatedMeshShader = new AnimatedMeshShader(m_d3d, m_pSettings);
		m_spriteShader = new SpriteShader(m_d3d, m_pSettings);



	}

	void Renderer::createRenderers()
	{
		m_aabbRenderer = new AABBRenderer(m_linesShader);
		m_objectsRenderer = new ObjectsRenderer(m_d3d);
		m_linesRenderer = new LinesRenderer(m_d3d, m_linesShader);
		m_particlesRenderer = new ParticlesRenderer(m_spriteShader);
	}

	void Renderer::createLight()
	{
		m_light = new Light(m_d3d);
		m_light->setup();
	}

	void Renderer::createCamera()
	{
		m_camera = new Camera(m_d3d);
		m_camera->setPosition(10, 10, 10);
		m_camera->lookAt(0, 0, 0);
		m_camera->setBuffer();
	}

	void Renderer::createPositionBuffer()
	{
		m_positionsBuffer = new PositionsBuffer(m_d3d, 1);
		m_positionsBuffer->setBuffer();
	}

	void Renderer::clear()
	{
		m_d3d->clear();
	}

	void Renderer::present()
	{
		m_d3d->present();
	}


	void Renderer::renderModel(Model* model, Position pos)
	{
		m_positionsBuffer->setPosition(pos);

		for (auto& mesh : model->m_meshes)
		{
			mesh->render();
		}


	}

	void Renderer::renderMesh(Mesh* mesh, Position pos)
	{
		m_positionsBuffer->setPosition(pos);
		mesh->render();
	}

	void Renderer::renderObjects()
	{
		for (auto& obj : *m_objects)
		{
			if (obj->getType() == ObjectType::OBJECT)
			{
				renderObject(obj);
				AABB* aabb = obj->getModel()->getAABB();
				m_aabbRenderer->render(aabb);
			}
		}
	}

	

	
	void Renderer::renderTrees()
	{
		std::list<Sprite3D> spriteList;

		for (auto& obj : *m_objects)
		{
			if (obj->getType() == ObjectType::TREE)
			{
				renderObject(obj);
				//AABB* aabb = obj->getModel()->getAABB();
				//m_aabbRenderer->render(aabb);

				Tree* t = (Tree*)obj;
				
				for (auto sprite : t->sprites)
				{
					sprite.position += obj->getPosition()->position;
					spriteList.push_back(sprite);					
				}
			}
		}

		Vector3 campos = m_camera->getPosition();

		spriteList.sort([campos](const Sprite3D& first, const Sprite3D& second) {
			return Helper::distance(first.position, campos) < Helper::distance(second.position, campos);
		});

		for (auto& sprite : spriteList)
		{
			sprite.rect.x *= sprite.scale.x;
			sprite.rect.y *= sprite.scale.y;
			sprite.rect.z *= sprite.scale.z;

			m_spriteShader->addSprite(sprite.rect, sprite.position, sprite.texture);
		}

		//m_d3d->turnZBuffer(false);
		m_spriteShader->render();
		//m_d3d->turnZBuffer(true);
		m_spriteShader->clear();
	}

	void Renderer::renderAgents()
	{
		for (auto& obj : *m_agents)
		{
			m_positionsBuffer->setPosition(*obj->getPosition());
			renderObject(obj);
			//m_aabbRenderer->render(&obj->getModel()->aabb);
		}
	}

	void Renderer::renderTerrain()
	{
		if (*m_terrain)
		{
			renderMesh(*m_terrain, Position());
		}
	}

	void Renderer::renderObject(Object* object)
	{
		if (object->visible == true)
		{
			m_positionsBuffer->setPosition(*object->getPosition());

			Model* model = object->getModel();

			for (const auto& mesh : model->m_meshes)
			{
				mesh->render();
				//m_aabbRenderer->render(mesh->getAABB());
			}
		}
	}

	void Renderer::renderDebugObjects()
	{
		Position pos;
		pos.position.z = 1;
		m_positionsBuffer->setPosition(pos);

		
		if (m_navmesh)
		{
			m_navmesh->setShader(m_colorShader);
			m_navmesh->render();
			m_navmesh->setShader(m_linesShader);
			m_navmesh->render();
		}
		

		/*
		if (debugLines.size())
		{
			for (int i = 0; i < debugLines.size(); i += 2)
			{
				m_linesRenderer->addLine(debugLines[i], debugLines[i + 1], Vector4(1, 0, 0, 1));
			}
			m_linesRenderer->render();
			m_linesRenderer->clear();
			debugLines.clear();

		}
		*/
		/*
		if (nodeLines.size())
		{
			for (int i = 0; i < nodeLines.size(); i += 2)
			{
				m_linesRenderer->addLine(nodeLines[i], nodeLines[i + 1], Vector4(1, 1, 0, 1));
			}
			m_linesRenderer->render();
			m_linesRenderer->clear();
		}
		*/

		debugLiner.setCategoryColor("nodepath", Vector4(0,1,0,1));
		debugLiner.setCategoryColor("path", Vector4(1, 0, 0, 1));
		debugLiner.setCategoryColor("portals", Vector4(0, 1, 1, 1));

		for (auto& linelist : *debugLiner.getCategories())
		{
			for (auto& line : linelist.second)
			{
				m_linesRenderer->addLine(line.from, line.to, line.color);
			}

			m_linesRenderer->render();
			m_linesRenderer->clear();
		}
	}

	void Renderer::renderManipulator()
	{
		m_d3d->turnZBuffer(false);
		if (m_manipulator->visible)
		{
			renderObject(m_manipulator);
		}
		m_d3d->turnZBuffer(true);
	}



	

	Camera* Renderer::getCamera()
	{
		return m_camera;
	}

	Light* Renderer::getLight()
	{
		return m_light;
	}

	void Renderer::setSelectedObject(Object* obj)
	{
		m_manipulator->setTarget(obj);
	}

	ManipulatorAxis* Renderer::getManipulator()
	{
		return m_manipulator;
	}

	Picker* Renderer::getPicker()
	{
		return m_picker;
	}

	Axis* Renderer::getAxis()
	{
		return axis;
	}

	Grid* Renderer::getGrid()
	{
		return grid;
	}

	void Renderer::render()
	{
		m_camera->updateBuffer();

		

		renderObject(axis);
		renderObject(grid);
		renderTerrain();
		renderObjects();
		renderTrees();
		renderAgents();
		renderManipulator();
		//renderDebugObjects();

		m_d3d->turnZBuffer(false);
		m_particlesRenderer->render(smoke);
		m_d3d->turnZBuffer(true);
		
	}
}