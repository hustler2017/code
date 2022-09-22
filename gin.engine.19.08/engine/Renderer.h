#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "IEngineSettings.h"
#include "Model.h"
#include "Object.h"
#include "Axis.h"
#include "Grid.h"
#include "Camera.h"
#include "Light.h"
#include "ManipulatorAxis.h"

#include "LinesShader.h"
#include "ColorShader.h"
#include "TerrainShader.h"
#include "AnimatedMeshShader.h"
#include "StaticMeshShader.h"
#include "SpriteShader.h"

#include <string>
#include <vector>
#include <map>
#include <list>

#include "AABBRenderer.h"
#include "ObjectsRenderer.h"
#include "Picker.h"
#include "Agent.h"
#include "LinesRenderer.h"
#include "ParticlesRenderer.h"
#include "Smoke.h"


#include "Liner.h"

namespace Engine
{
	class Renderer
	{
		
		IEngineSettings* m_pSettings;
		Picker* m_picker;
		
		std::list<Model*>* m_models;
		std::list<Object*>* m_objects;
		std::list<Agent*>* m_agents;

		ObjectsRenderer* m_objectsRenderer;
		AABBRenderer* m_aabbRenderer;
		ParticlesRenderer* m_particlesRenderer;
		Light* m_light;
		Camera* m_camera;		
		ManipulatorAxis* m_manipulator;
		PositionsBuffer* m_positionsBuffer;

		Axis* axis;
		Grid* grid;

		Terrain** m_terrain;
			
		Smoke* smoke;

		void createShaders();
		void createRenderers();
		void createLight();
		void createCamera();
		void createPositionBuffer();
		void createAxis();
		void createGrid();
		void createManipulator();

		void renderObjects();
		void renderTrees();
		void renderAgents();
		void renderTerrain();
		void renderManipulator();
		void renderDebugObjects();
		void renderObject(Object* object);


	public:	
		Graphics::Direct3D* m_d3d;

		LinesRenderer* m_linesRenderer;
		LinesShader* m_linesShader;
		ColorShader* m_colorShader;
		TerrainShader* m_terrainShader;
		AnimatedMeshShader* m_animatedMeshShader;
		StaticMeshShader* m_staticMeshShader;
		SpriteShader* m_spriteShader;
		std::vector<Vector3> nodeLines;
		std::vector<Vector3> pathNodeLines;
		Mesh* m_navmesh;

		Liner debugLiner;

		Renderer(
			Graphics::Direct3D* d3d, 
			IEngineSettings* pSettings,
			std::list<Model*>* models,
			std::list<Object*>* objects,
			std::list<Agent*>* agents,
			Terrain** terrain
		);
		~Renderer();
		
		void clear();
		void render();
		void present();
		void renderModel(Model* model, Position pos);
		void renderMesh(Mesh* mesh, Position pos);
		Camera* getCamera();
		Light* getLight();
		void setSelectedObject(Object* obj);
		ManipulatorAxis* getManipulator();
		Picker* getPicker();
		Axis* getAxis();
		Grid* getGrid();

		void onEngineUpdate();
		
		
	};
}

