#pragma once
#include "Common.h"
#include <map>
#include <vector>
#include <string>

namespace Engine
{
	class Liner
	{
	public:
		
		struct Line
		{
			Vector3 from;
			Vector3 to;
			Vector4 color;
		};

	private:
		std::map<std::string, std::vector<Line>> m_lines;

	public:
		Liner();
		~Liner();

		void addLine(std::string category, Vector3 from, Vector3 to, Vector4 color);
		void addLine(std::string category, Vector3 from, Vector3 to);
		void clearLines(std::string category);
		std::vector<Line>* getLines(std::string category);
		std::map<std::string, std::vector<Line>>* getCategories();
		void setCategoryColor(std::string category, Vector4 color);
	};
}

