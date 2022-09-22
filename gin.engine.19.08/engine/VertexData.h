#pragma once
#include "pch.h"
#include "IVertexData.h"
#include <vector>

namespace Engine
{
	class VertexData : public IVertexData
	{
	private:
	
		unsigned int* m_polygons;
		unsigned int m_polygons_count;

		Vector3* m_coordinates;
		unsigned int m_coords_count;

		Vector4* m_colors;
		unsigned int m_colors_count;

		Vector3* m_normals;
		unsigned int m_normals_count;


		unsigned int* m_indices;
		unsigned int m_indices_count;

		Vector2** m_uv;
		unsigned int m_uv_channel_count;
		unsigned int m_uv_count;
		
		
		unsigned int** m_bones;
		float** m_weights;
		unsigned int m_bones_count;
		unsigned int m_bones_channels_count;

		inline void createUVBuffers();
		inline void deleteUVBuffers();

		inline void createBoneBuffers();
		inline void deleteBoneBuffers();
	public:
		VertexData();
		~VertexData();

		// Polygons:

		unsigned int getPolygonCount();
		bool setPolygonCount(unsigned int count);
		bool setPolygonVertex(unsigned int polygonIndex, unsigned int vertexIndex, unsigned int index);
		bool setPolygon(unsigned int polygonIndex, unsigned int CoordinateIndex1, unsigned int CoordinateIndex2, unsigned int CoordinateIndex3);
		unsigned int getPolygonVertex(unsigned int polygonIndex, unsigned int vertexIndex);

		// Coordinates:

		unsigned int getCoordinatesCount();
		bool setCoordinatesCount(unsigned int count);
		bool setCoordinates(unsigned int index, Vector3 coordinates);
		Vector3 getCoordinates(unsigned int index);

		// Normals

		unsigned int getNormalCount();
		bool setNormalCount(unsigned int count);
		bool setNormal(unsigned int index, Vector3 normal);
		Vector3 getNormal(unsigned int index);

		// Colors

		unsigned int getColorCount();
		bool setColorCount(unsigned int count);
		bool setColor(unsigned int index, Vector4 color);
		Vector4 getColor(unsigned int index);

		// Bones

		unsigned int getBonesCount();
		bool setBonesCount(unsigned int count);
		bool setBone(unsigned int channel, unsigned int index, unsigned int bone_id, float weight);
		unsigned int getBoneIndex(unsigned int channel, unsigned int index);
		float getBoneWeight(unsigned int channel, unsigned int index);
		unsigned int getBoneChannelCount();
		bool setBoneChannelCount(unsigned int count);

		// Indices

		unsigned int getIndicesCount();
		bool setIndicesCount(unsigned int count);
		unsigned int getIndex(unsigned int indexOfIndex);
		bool setIndex(unsigned int indexOfIndex, unsigned int value);

		// UV coords

		unsigned int getUVChannelCount();
		unsigned int setUVChannelCount(unsigned int count);
		void setUVCount(unsigned int count);
		unsigned int getUVCount();
		Vector2 getUV(unsigned int channel, unsigned int index);
		bool setUV(unsigned int channel, unsigned int index, Vector2 uv);
	};
}

