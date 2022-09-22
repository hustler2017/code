#pragma once

#include "Common.h"

namespace Engine
{
	class IGeometry
	{
	public:
		virtual void setVertexCount(int count) = 0;
		virtual void setVertexNormal(int vertex, Vector3& normal) = 0;
		virtual void setVertexBone(int vertex, int slot, int bone, float weight) = 0;
		virtual void setVertexUV(int vertex, int slot, Vector2& uv) = 0;
		virtual void setVertexCoords(int vertex, Vector3& coordinates) = 0;
		virtual int getStride() = 0;
		virtual void* getVertexBuffer() = 0;
		virtual bool hasIndices() = 0;
		virtual int getVertexCount() = 0;
		virtual int getIndicesCount() = 0;
		virtual unsigned int* getIndicesBuffer() = 0;
		virtual int getVertexBufferSize() = 0;
		virtual int getIndicesBufferSize() = 0;
		virtual Vector3 getVertexCoordinates(int vertexIndex) = 0;
		virtual Vector3 getVertexNormal(int vertexIndex) = 0;
		virtual Vector2 getVertexUV(int vertexIndex, int channelIndex) = 0;
		virtual Vector4 getVertexColor(int vertexIndex) = 0;
	};
}

