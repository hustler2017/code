#pragma once
#include "pch.h"
#include "dllexport.h"

namespace Engine
{
	std::wstring cctowstr(const char* c)
	{
		std::string s(c);
		std::wstring w(s.begin(), s.end());
		return w;
	};


	const char* wstrtocc(std::wstring ws)
	{
		std::string s(ws.begin(), ws.end());
		return s.c_str();
	};

#pragma region Engine

	
	Engine* engine_create(EngineSettingsMarshal s)
	{
		EngineSettings* settings = new EngineSettings();
		settings->setPath(L"textures", cctowstr(s.texturesDirectory));
		settings->setPath(L"models", cctowstr(s.modelsDirectory));
		settings->setPath(L"shaders", cctowstr(s.shadersDirectory));
		settings->setHWnd(s.windowHandler);
		return new Engine(settings);
	}

	void engine_delete(Engine* pEngine)
	{
		delete pEngine;
	}

	void engine_render(Engine* engine)
	{
		engine->render();
	}

	


#pragma endregion Engine

#pragma region Model

	Model* engine_load_model(Engine* engine, const char* filename)
	{
		return engine->loadModel(cctowstr(filename));
	}

#pragma endregion Model


#pragma region Object
	

	Object* engine_create_object(Engine* engine, Model* model)
	{
		return engine->createObject(model);
	}

	void engine_delete_object(Engine* engine, Object* object)
	{
		engine->removeObject(object);
	}

	Vector3 engine_get_object_position(Engine* engine, Object* object)
	{
		return object->getPosition()->position;
	}

	void engine_set_object_position(Engine* engine, Object* object, Vector3 pos)
	{
		object->getPosition()->position = pos;
	}
	Vector3 engine_get_object_rotation(Engine* engine, Object* object)
	{
		return object->getPosition()->rotation;
	}

	void engine_set_object_rotation(Engine* engine, Object* object, Vector3 rot)
	{
		object->getPosition()->rotation = rot;
	}
	Vector3 engine_get_object_scale(Engine* engine, Object* object)
	{
		return object->getPosition()->scale;
	}

	void engine_set_object_scale(Engine* engine, Object* object, Vector3 scale)
	{
		object->getPosition()->scale = scale;
	}


#pragma endregion Object


#pragma region Light

	Light* engine_get_light(Engine* engine)
	{
		return engine->getLight();
	}

	Vector3 engine_get_light_direction(Light* light)
	{
		return light->getDirection();
	}

	void engine_set_light_direction(Light* light, Vector3 dir)
	{
		light->setDirection(dir);
	}

	Vector3 engine_get_light_color(Light* light)
	{
		return light->getColor();
	}

	void engine_set_light_color(Light* light, Vector3 color)
	{
		light->setColor(color);
	}

	Vector3 engine_get_light_position(Light* light)
	{
		return light->getPosition();
	}

	void engine_set_light_position(Light* light, Vector3 pos)
	{
		light->setPosition(pos);
	}

	float engine_get_light_intensity(Light* light)
	{
		return light->getIntensity();

	}

	void engine_set_light_intensity(Light* light, float intensity)
	{
		light->setIntensity(intensity);
	}

#pragma endregion Light


#pragma region Camera

	Camera* engine_get_camera(Engine* engine)
	{
		return engine->getCamera();
	}

	void camera_move(Camera* camera, float x, float y, float z)
	{
		camera->move(x, y, z);
	}

	void camera_turn(Camera* camera, float x, float y, float z)
	{
		camera->turn(x, y, z);
	}

	void camera_look_at(Camera* camera, float x, float y, float z)
	{
		camera->lookAt(x, y, z);
	}


	void camera_set_position(Camera* camera, float x, float y, float z)
	{
		camera->setPosition(x, y, z);
	}

	void camera_set_rotation(Camera* camera, float x, float y, float z)
	{
		camera->setRotation(x, y, z);
	}
		
	void camera_set_fow(Camera* camera, float fow)
	{
		camera->setFOW(fow);
	}
	
	Vector3 camera_get_position(Camera* camera)
	{
		return camera->getPosition();
	}

	Vector3 camera_get_rotation(Camera* camera)
	{
		return camera->getRotation();
	}

	float camera_get_fow(Camera* camera)
	{
		return camera->getFOW();
	}

#pragma endregion Camera

#pragma region Terrain

	Terrain* engine_get_terrain(Engine* engine)
	{
		return engine->getTerrain();
	}

	void engine_set_terrain_channel_texture(Terrain* pTerrain, int channel, const char* filename)
	{
		auto vec = pTerrain->getTextures();   
		(*vec)[channel] = cctowstr(filename);
	}

	BSTR engine_get_terrain_channel_texture(Terrain* pTerrain, int channel)
	{
		std::wstring wstr = (*(pTerrain->getTextures()))[channel];
		return SysAllocStringLen(wstr.data(), wstr.size());
	}

	float engine_get_terrain_channel_tilingX(Terrain* pTerrain, int channel)
	{
		return (pTerrain->getTiling(channel)).x;
	}

	float engine_get_terrain_channel_tilingY(Terrain* pTerrain, int channel)
	{
		return (pTerrain->getTiling(channel)).y;
	}

	void engine_set_terrain_channel_tilingX(Terrain* pTerrain, int channel, float tiling)
	{
		Vector2 v = pTerrain->getTiling(channel);
		v.x = tiling;
		pTerrain->setTiling(channel, v);
	}

	void engine_set_terrain_channel_tilingY(Terrain* pTerrain, int channel, float tiling)
	{
		Vector2 v = pTerrain->getTiling(channel);
		v.y = tiling;
		pTerrain->setTiling(channel, v);
	}

	int engine_get_terrain_channels_count(Terrain* pTerrain)
	{
		return pTerrain->getTextureChannels();
	}

#pragma endregion Terrain

#pragma region Animation

	BSTR engine_get_object_animation_names(Object* obj)
	{
		std::vector<std::string> names = obj->getModel()->m_meshes[0]->getAnimationNames();
		std::wstring names_string = L"";
		for (int i = 0; i < names.size(); i++)
		{
			names_string += L"," + std::wstring(names[i].begin(), names[i].end());
		}
		return SysAllocStringLen(names_string.data(), names_string.size());
	}

	void engine_load_object_animation(Engine* engine, Object* object, const char* filename, const char* name)
	{
		engine->loadAnimation(object->getModel()->m_meshes[0], cctowstr(filename), name);
	}


	void engine_play_object_animation(Object* object, const char* animName)
	{
		object->getModel()->m_meshes[0]->startAnimation(animName);
	}


#pragma endregion Animation


#pragma region Axis

	Axis* engine_get_axis_object(Engine* engine)
	{
		return engine->getAxis();
	}

	void engine_set_axis_status(Axis* axis, bool status)
	{
		axis->setVisible(status);
	}

	bool engine_get_axis_status(Axis* axis)
	{
		return axis->getVisible();
	}

#pragma endregion Axis


#pragma region Grid

	Grid* engine_get_grid_object(Engine* engine)
	{
		return engine->getGrid();
	}

	void engine_set_grid_size(Grid* grid, float size)
	{
		grid->setSize(size);
	}


	void engine_set_grid_density(Grid* grid, float density)
	{
		grid->setDensity(density);
	}

	float engine_get_grid_size(Grid* grid)
	{
		return grid->getSize();
	}

	float engine_get_grid_density(Grid* grid)
	{
		return grid->getDensity();
	}

#pragma endregion Grid

#pragma region Manipulator

	ManipulatorAxis* engine_get_manipulator(Engine* engine)
	{
		return engine->getManipulator();
	}

	int engine_check_manipulator_picking(ManipulatorAxis* manipulator, int x, int y)
	{
		if (manipulator->visible == false) return 0;
		return manipulator->checkPicking(x, y);
	}

	void engine_show_manipulator(ManipulatorAxis* manipulator, bool flag)
	{
		manipulator->visible = flag;
	}

	void engine_manipulator_set_target(ManipulatorAxis* manipulator, Object* obj)
	{
		manipulator->setTarget(obj);
	}

#pragma endregion Manipulator


#pragma region Picking

	Object* engine_get_picked_object(Engine* engine, int x, int y)
	{
		return engine->getPickedObject(x, y);
	}

	Agent* engine_get_picked_agent(Engine* engine, int x, int y)
	{
		return engine->getPickedAgent(x, y);
	}



#pragma endregion Picking


#pragma region Agents
	Agent* engine_create_agent(Engine* engine, int x, int y)
	{
		return engine->createAgent();
	}
#pragma endregion Agents



	void engine_start_game(Engine* engine)
	{
		engine->start();
	}

	void engine_stop_game(Engine* engine)
	{
		engine->stop();
	}

	void engine_command_move(Engine* engine, Agent* agent, int x, int y)
	{
		engine->commandMove(agent, x, y);
	}


}