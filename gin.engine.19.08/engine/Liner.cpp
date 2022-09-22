#include "pch.h"
#include "Liner.h"

namespace Engine
{
	Liner::Liner()
	{

	}
	Liner::~Liner()
	{

	}

	void Liner::addLine(std::string category, Vector3 from, Vector3 to)
	{
		{
			Line line = { from, to, Vector4(1,1,1,1) };
			m_lines[category].push_back(line);
		}
	}

	void Liner::addLine(std::string category, Vector3 from, Vector3 to, Vector4 color)
	{
		{
			Line line = { from, to, color };
			m_lines[category].push_back(line);
		}
	}
	void Liner::clearLines(std::string category)
	{
		if (m_lines.find(category) == m_lines.end())
		{
			return;
		}

		m_lines[category].clear();
	}

	std::vector<Liner::Line>* Liner::getLines(std::string category)
	{
		return &m_lines[category];
	}

	std::map<std::string, std::vector<Liner::Line>>* Liner::getCategories()
	{
		return &m_lines;
	}


	void Liner::setCategoryColor(std::string category, Vector4 color)
	{
		if (m_lines.find(category) != m_lines.end())
		{
			for (auto& line : m_lines[category])
			{
				line.color = color;
			}
		}
	}
}