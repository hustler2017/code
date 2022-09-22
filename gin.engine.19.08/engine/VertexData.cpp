#include "pch.h"
#include "VertexData.h"

namespace Engine
{
	VertexData::VertexData()
		: m_polygons(nullptr),
		m_coordinates(nullptr),
		m_colors(nullptr),
		m_normals(nullptr),
		m_indices(nullptr),
		m_uv(nullptr),
		m_bones(nullptr),
		m_weights(nullptr),

		m_polygons_count(0),
		m_coords_count(0),
		m_colors_count(0),
		m_normals_count(0),
		m_indices_count(0),
		m_uv_channel_count(0),
		m_uv_count(0),
		m_bones_count(0),
		m_bones_channels_count(0)
	{
	}
	
	VertexData::~VertexData()
	{
		if(m_polygons)		delete[] m_polygons;
		if(m_coordinates)	delete[] m_coordinates;
		if(m_colors)		delete[] m_colors;
		if(m_normals)		delete[] m_normals;
		if(m_indices)		delete[] m_indices;

		deleteUVBuffers();
		deleteBoneBuffers();
	}

	inline void  VertexData::createUVBuffers()
	{
		m_uv = new Vector2 * [m_uv_channel_count];
		for (int i = 0; i < m_uv_channel_count; i++)
		{
			m_uv[i] = new Vector2[m_uv_count];
		}
	}

	inline void  VertexData::deleteUVBuffers()
	{
		if (m_uv_channel_count)
		{
			for (int i = 0; i < m_uv_channel_count; i++)
			{
				if (m_uv[i])
				{
					delete[] m_uv[i];
				}
			}

			delete[] m_uv;
		}
	}

	inline void  VertexData::createBoneBuffers()
	{
		m_bones = new unsigned int* [m_bones_channels_count];
		m_weights = new float* [m_bones_channels_count];
		for (int i = 0; i < m_bones_channels_count; i++)
		{
			m_bones[i] = new unsigned int[m_bones_count];
			m_weights[i] = new float[m_bones_count];
		}
	}

	inline void  VertexData::deleteBoneBuffers()
	{
		if (m_bones)
		{
			for (int i = 0; i < m_bones_channels_count; i++)
			{
				delete[] m_bones[i];
			}

			delete[] m_bones;
		}

		if (m_weights)
		{
			for (int i = 0; i < m_bones_channels_count; i++)
			{
				delete[] m_weights[i];
			}

			delete[] m_weights;
		}
	}

	unsigned int VertexData::getPolygonCount()
	{
		return m_polygons_count;
	}

	bool VertexData::setPolygonCount(unsigned int count)
	{
		m_polygons_count = count;
		unsigned int values_count = count * 3;
		if(m_polygons) delete[] m_polygons;
		m_polygons = new unsigned int[values_count];
		return true;
	}

	bool VertexData::setPolygonVertex(unsigned int polygonIndex, unsigned int vertexIndex, unsigned int index)
	{
		if (polygonIndex < m_polygons_count)
		{
			if (vertexIndex < 3)
			{
				m_polygons[polygonIndex * 3 + vertexIndex] = index;
				return true;
			}
		}

		return false;
	}

	bool VertexData::setPolygon(unsigned int polygonIndex, unsigned int CoordinateIndex1, unsigned int CoordinateIndex2, unsigned int CoordinateIndex3)
	{
		
		if (polygonIndex < m_polygons_count)
		{
			unsigned int offset = polygonIndex * 3;
			m_polygons[offset + 0] = CoordinateIndex1;
			m_polygons[offset + 1] = CoordinateIndex2;
			m_polygons[offset + 2] = CoordinateIndex3;

			return true;
		}
		return false;
	}

	unsigned int VertexData::getPolygonVertex(unsigned int polygonIndex, unsigned int vertexIndex)
	{
		if (polygonIndex < m_polygons_count)
		{
			if (vertexIndex < 3)
			{
				return m_polygons[polygonIndex * 3 + vertexIndex];
			}
		}

		return 0;
	}

	// Coordinates:

	unsigned int VertexData::getCoordinatesCount()
	{
		return m_coords_count;
	}

	bool VertexData::setCoordinatesCount(unsigned int count)
	{
		m_coords_count = count;
		if(m_coordinates) delete[] m_coordinates;
		m_coordinates = new Vector3[m_coords_count];
		return true;
	}

	bool VertexData::setCoordinates(unsigned int index, Vector3 coordinates)
	{
		if (index < m_coords_count)
		{
			m_coordinates[index] = coordinates;
			return true;
		}

		return false;
	}

	Vector3 VertexData::getCoordinates(unsigned int index)
	{
		if (index < m_coords_count)
		{
			return m_coordinates[index];
		}

		return Vector3(0, 0, 0);
	}

	// Normals

	unsigned int VertexData::getNormalCount()
	{
		return m_normals_count;
	}

	bool VertexData::setNormalCount(unsigned int count)
	{
		m_normals_count = count;
		if (m_normals) delete[] m_normals;
		m_normals = new Vector3[m_normals_count];
		return true;
	}

	bool VertexData::setNormal(unsigned int index, Vector3 normal)
	{
		if (index < m_normals_count)
		{
			m_normals[index] = normal;
			return true;
		}

		return false;
	}

	Vector3 VertexData::getNormal(unsigned int index)
	{
		if (index < m_normals_count)
		{
			return m_normals[index];
		}

		return Vector3(0, 0, 0);
	}

	// Colors

	unsigned int VertexData::getColorCount()
	{
		return m_colors_count;
	}

	bool VertexData::setColorCount(unsigned int count)
	{
		m_colors_count = count;
		if (m_colors) delete[] m_colors;
		m_colors = new Vector4[m_colors_count];
		return true;
	}

	bool VertexData::setColor(unsigned int index, Vector4 color)
	{
		if (index < m_colors_count)
		{
			m_colors[index] = color;
			return true;
		}

		return false;
	}

	Vector4 VertexData::getColor(unsigned int index)
	{
		if (index < m_colors_count)
		{
			return m_colors[index];
		}
	
		return Vector4(1, 1, 1, 1);
	}

	// Bones

	unsigned int VertexData::getBonesCount()
	{
		return m_bones_count;
	}

	bool VertexData::setBonesCount(unsigned int count)
	{
		m_bones_count = count;
		deleteBoneBuffers();
		createBoneBuffers();
		return true;
	}

	bool VertexData::setBone(unsigned int channel, unsigned int index, unsigned int bone_id, float weight)
	{
		if (channel < m_bones_channels_count)
		{
			if (index < m_bones_count)
			{
				m_bones[channel][index] = bone_id;
				m_weights[channel][index] = weight;

				return true;
			}
		}

		return false;
	}

	unsigned int VertexData::getBoneIndex(unsigned int channel, unsigned int index)
	{
		if (channel < m_bones_channels_count)
		{
			if (index < m_bones_count)
			{
				return m_bones[channel][index];
			}
		}

		return 0;
	}

	float VertexData::getBoneWeight(unsigned int channel, unsigned int index)
	{
		if (channel < m_bones_channels_count)
		{
			if (index < m_bones_count)
			{
				return m_weights[channel][index];
			}
		}

		return 0.0f;
	}

	unsigned int VertexData::getBoneChannelCount()
	{
		return m_bones_channels_count;
	}

	bool VertexData::setBoneChannelCount(unsigned int count)
	{
		m_bones_channels_count = count;
		deleteBoneBuffers();
		createBoneBuffers();
		return true;
	}

	// Indices

	unsigned int VertexData::getIndicesCount()
	{
		return m_indices_count;
	}

	bool VertexData::setIndicesCount(unsigned int count)
	{
		m_indices_count = count;
		if (m_indices) delete[] m_indices;
		m_indices = new unsigned int[m_indices_count];
		return true;
	}

	unsigned int VertexData::getIndex(unsigned int index)
	{
		if (index < m_indices_count)
		{
			return m_indices[index];
		}

		return 0;
	}

	bool VertexData::setIndex(unsigned int index, unsigned int value)
	{
		if (index < m_indices_count)
		{
			m_indices[index] = value;
			return true;
		}

		return false;
	}

	// UV coords

	unsigned int VertexData::getUVChannelCount()
	{
		return m_uv_channel_count;
	}

	unsigned int VertexData::setUVChannelCount(unsigned int count)
	{
		deleteUVBuffers();
		m_uv_channel_count = count;
		createUVBuffers();
		return true;
	}

	void VertexData::setUVCount(unsigned int count)
	{
		deleteUVBuffers();
		m_uv_count = count;
		createUVBuffers();
	}

	unsigned int VertexData::getUVCount()
	{
		return m_uv_count;
	}

	Vector2 VertexData::getUV(unsigned int channel, unsigned int index)
	{
		if (channel < m_uv_channel_count)
		{
			if (index < m_uv_count)
			{
				return m_uv[channel][index];
			}
		}

		return Vector2(0, 0);
	}

	bool VertexData::setUV(unsigned int channel, unsigned int index, Vector2 uv)
	{
		if (channel < m_uv_channel_count)
		{
			if (index < m_uv_count)
			{
				m_uv[channel][index] = uv;
				return true;
			}
		}

		return false;
	}
}