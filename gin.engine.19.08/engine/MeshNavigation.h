#pragma once
#include "INavigation.h"
#include "Mesh.h"
#include "NavMesh.h"
#include "Graph.h"
#include "Liner.h";


namespace Engine
{
	namespace Navigation
	{
		class MeshNavigation : public INavigation
		{
		private:
			NavMesh* m_navmesh;
			Graph* m_graph;
			Liner* pLiner;

			void FunnelSearch(Vector2& from, Vector2& to, std::list<GraphNode*>& nodePath, std::list<Vector2>& path);
			void FunnelSearch2(Vector2& from, Vector2& to, std::list<GraphNode*>& nodePath, std::list<Vector2>& path);
		public:
			MeshNavigation(IVertexData* vd, Liner* liner);
			~MeshNavigation();
			bool FindPath(Vector2 from, Vector2 to, std::list<Vector2>& path);
			void fillNodeLinks(std::vector<Vector3>* vec);

		};
	}
}

