#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "SpriteRendererShader.h"

#include <vector>

class SpriteRenderer
{
public:
	struct SpriteRect
	{
		float left_x;
		float top_y;
		float right_x;
		float bottom_y;

		SpriteRect(float left, float top, float right, float bottom)
			: left_x(left), top_y(top), right_x(right), bottom_y(bottom)
		{

		}
	};


	struct SpritePosition
	{
		float x;
		float y;
		float z;

		SpritePosition(float _x, float _y, float _z)
			: x(_x), y(_y), z(_z)
		{

		}
	};

	struct Vertex
	{
		float x;
		float y;
		float z;
		float u;
		float v;
	};

private:


	struct InstanceData
	{
		float x;
		float y;
		float z;
		int texture_ind;
	};


	std::vector< ID3D11ShaderResourceView*> m_textures;
	int m_sprites_max_count;
	int m_sprites_count;
	InstanceData* m_instance_buffer;
	InstanceData* m_instance_buffer_pointer;

	Graphics::Direct3D* m_d3d;
	SpriteRendererShader* m_shader;
	ID3D11Buffer* m_pVertexBuffer;
	ID3D11Buffer* m_pInstanceBuffer;
	int m_verticies_max_count;
	int m_verticies_count;
	Vertex* m_verticies;
	Vertex* m_buffer_pointer;


	void createBuffer();
	void createInstanceBuffer();
	void createResources();
	void freeResources();

	int addTexture(ID3D11ShaderResourceView* texture);
	inline void addVertex(float x, float y, float u, float v);
	inline void addQuad(SpriteRect quad);
	inline void addPosition(SpritePosition pos);
	
public:
	SpriteRenderer(Graphics::Direct3D* d3d);
	~SpriteRenderer();
	void addSprite(SpriteRect rect, SpritePosition pos, ID3D11ShaderResourceView* texture);
	void render();
	void clear();
};

