#pragma once
#include "pch.h"
#include "Engine.h"
#include <comdef.h>

namespace Engine
{
	extern "C" {

		struct EngineSettingsMarshal
		{
			const char* modelsDirectory;
			const char* texturesDirectory;
			const char* shadersDirectory;
			HWND windowHandler;
		};

		// engine
		__declspec(dllexport) Engine* engine_create(EngineSettingsMarshal settings);
		__declspec(dllexport) void engine_delete(Engine* pEngine);
		__declspec(dllexport) void engine_render(Engine* engine);
		
		
		// model
		__declspec(dllexport) Model* engine_load_model(Engine* engine, const char* filename);
		
		// object
		__declspec(dllexport) Object* engine_create_object(Engine* engine, Model* model);
		__declspec(dllexport) void engine_delete_object(Engine* engine, Object* object);
		__declspec(dllexport) Vector3 engine_get_object_position(Engine* engine, Object* object);
		__declspec(dllexport) void engine_set_object_position(Engine* engine, Object* object, Vector3 pos);
		__declspec(dllexport) Vector3 engine_get_object_rotation(Engine* engine, Object* object);
		__declspec(dllexport) void engine_set_object_rotation(Engine* engine, Object* object, Vector3 scale);
		__declspec(dllexport) Vector3 engine_get_object_scale(Engine* engine, Object* object);
		__declspec(dllexport) void engine_set_object_scale(Engine* engine, Object* object, Vector3 scale);
		
		
		// light
		__declspec(dllexport)  Light* engine_get_light(Engine* engine);
		__declspec(dllexport) Vector3 engine_get_light_direction(Light* light);
		__declspec(dllexport) void engine_set_light_direction(Light* light, Vector3 dir);
		__declspec(dllexport) Vector3 engine_get_light_color(Light* light);
		__declspec(dllexport) void engine_set_light_color(Light* light, Vector3 color);
		__declspec(dllexport) Vector3 engine_get_light_position(Light* light);
		__declspec(dllexport) void engine_set_light_position(Light* light, Vector3 pos);
		__declspec(dllexport) float engine_get_light_intensity(Light* light);
		__declspec(dllexport) void engine_set_light_intensity(Light* light, float intensity);

		// camera
		__declspec(dllexport) Camera* engine_get_camera(Engine* engine);
		__declspec(dllexport) void camera_move(Camera* camera, float x, float y, float z);
		__declspec(dllexport) void camera_turn(Camera* camera, float x, float y, float z);
		__declspec(dllexport) void camera_look_at(Camera* camera, float x, float y, float z);
		__declspec(dllexport) void camera_set_position(Camera* camera, float x, float y, float z);
		__declspec(dllexport) void camera_set_rotation(Camera* camera, float x, float y, float z);
		__declspec(dllexport) void camera_set_fow(Camera* camera, float fow);
		__declspec(dllexport) Vector3 camera_get_position(Camera* camera);
		__declspec(dllexport) Vector3 camera_get_rotation(Camera* camera);
		__declspec(dllexport) float camera_get_fow(Camera* camera);
		
		
		// terrain
		__declspec(dllexport) Terrain* engine_get_terrain(Engine* engine);
		__declspec(dllexport) void engine_set_terrain_channel_texture(Terrain* pTerrain, int channel, const char* filename);
		__declspec(dllexport) BSTR engine_get_terrain_channel_texture(Terrain* pTerrain, int channel);
		__declspec(dllexport) float engine_get_terrain_channel_tilingX(Terrain* pTerrain, int channel);
		__declspec(dllexport) float engine_get_terrain_channel_tilingY(Terrain* pTerrain, int channel);
		__declspec(dllexport) void engine_set_terrain_channel_tilingX(Terrain* pTerrain, int channel, float tiling);
		__declspec(dllexport) void engine_set_terrain_channel_tilingY(Terrain* pTerrain, int channel, float tiling);
		__declspec(dllexport) int engine_get_terrain_channels_count(Terrain* pTerrain);
		
		// animation
		__declspec(dllexport) BSTR engine_get_object_animation_names(Object* obj);
		__declspec(dllexport) void engine_load_object_animation(Engine* engine, Object* object, const char*  filename, const char* name);
		__declspec(dllexport) void engine_play_object_animation(Object* object, const char* animName);

		// axis
		__declspec(dllexport) Axis* engine_get_axis_object(Engine* engine);
		__declspec(dllexport) void engine_set_axis_status(Axis* axis, bool status);
		__declspec(dllexport) bool engine_get_axis_status(Axis* axis);
		
		// grid
		__declspec(dllexport) Grid* engine_get_grid_object(Engine* engine);
		__declspec(dllexport) void engine_set_grid_size(Grid* grid, float size);
		__declspec(dllexport) void engine_set_grid_density(Grid* grid, float density);
		__declspec(dllexport) float engine_get_grid_size(Grid* grid);
		__declspec(dllexport) float engine_get_grid_density(Grid* grid);

		//manipulator

		__declspec(dllexport) int engine_check_manipulator_picking(ManipulatorAxis* manipulator, int x, int y);
		__declspec(dllexport) ManipulatorAxis* engine_get_manipulator(Engine* engine); 
		__declspec(dllexport) void engine_show_manipulator(ManipulatorAxis* manipulator, bool flag);
		__declspec(dllexport) void engine_manipulator_set_target(ManipulatorAxis* manipulator, Object* obj);
		//picking
		__declspec(dllexport) Object* engine_get_picked_object(Engine* engine, int x, int y);
		__declspec(dllexport) Agent* engine_get_picked_agent(Engine* engine, int x, int y);

		// agents
		__declspec(dllexport) Agent* engine_create_agent(Engine* engine, int x, int y);

		// game 

		__declspec(dllexport) void engine_start_game(Engine* engine);
		__declspec(dllexport) void engine_stop_game(Engine* engine);


		// commands
		__declspec(dllexport) void engine_command_move(Engine* engine, Agent* agent, int x, int y);
	}
}