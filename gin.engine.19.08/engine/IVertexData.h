#pragma once
#include "pch.h"
#include "Common.h"

namespace Engine
{
	class IVertexData
	{
	public:

		// Polygons

		virtual unsigned int getPolygonCount() = 0;
		virtual bool setPolygonCount(unsigned int count) = 0;
		virtual bool setPolygonVertex(unsigned int polygonIndex, unsigned int vertexIndex, unsigned int index) = 0;
		virtual bool setPolygon(unsigned int polygonIndex, unsigned int CoordinateIndex1, unsigned int CoordinateIndex2, unsigned int CoordinateIndex3) = 0;
		virtual unsigned int getPolygonVertex(unsigned int polygonIndex, unsigned int vertexIndex) = 0;

		// Coordinates:

		virtual unsigned int getCoordinatesCount() = 0;
		virtual bool setCoordinatesCount(unsigned int count) = 0;
		virtual bool setCoordinates(unsigned int index, Vector3 coordinates) = 0;
		virtual Vector3 getCoordinates(unsigned int index) = 0;

		// Normals

		virtual unsigned int getNormalCount() = 0;
		virtual bool setNormalCount(unsigned int count) = 0;
		virtual bool setNormal(unsigned int index, Vector3 normal) = 0;
		virtual Vector3 getNormal(unsigned int index) = 0;

		// Colors

		virtual unsigned int getColorCount() = 0;
		virtual bool setColorCount(unsigned int count) = 0;
		virtual bool setColor(unsigned int index, Vector4 color) = 0;
		virtual Vector4 getColor(unsigned int index) = 0;

		// Bones

		virtual unsigned int getBonesCount() = 0;
		virtual bool setBonesCount(unsigned int count) = 0;
		virtual bool setBone(unsigned int channel, unsigned int index, unsigned int bone_id, float weight) = 0;
		virtual unsigned int getBoneIndex(unsigned int channel, unsigned int index) = 0;
		virtual float getBoneWeight(unsigned int channel, unsigned int index) = 0;
		virtual unsigned int getBoneChannelCount() = 0;
		virtual bool setBoneChannelCount(unsigned int count) = 0;

		// Indices

		virtual unsigned int getIndicesCount() = 0;
		virtual bool setIndicesCount(unsigned int count) = 0;
		virtual unsigned int getIndex(unsigned int indexOfIndex) = 0;
		virtual bool setIndex(unsigned int indexOfIndex, unsigned int value) = 0;

		// UV coords

		virtual unsigned int getUVChannelCount() = 0;
		virtual unsigned int setUVChannelCount(unsigned int count) = 0;
		virtual void setUVCount(unsigned int size) = 0;
		virtual unsigned int getUVCount() = 0;
		virtual Vector2 getUV(unsigned int channel, unsigned int index) = 0;
		virtual bool setUV(unsigned int channel, unsigned int index, Vector2 uv) = 0;

		virtual ~IVertexData() {};
	};
}



