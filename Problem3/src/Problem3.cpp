#include "Problem3.h"

const double& Line::GetNodeDistance(const Node& n1, const Node& n2)
{
	return std::sqrt(std::pow(n1.x - n2.x, 2.0f) + std::pow(n1.y - n2.y, 2.0f));
}

Problem3::Problem3(std::string filepath)
{
	text.SetFilePath(filepath);
	text.ReadFile();
	SetNodes();
}

void Problem3::SetNodes()
{
	for (int i = 0; i < text.GetIntInText().GetSize(); i++)
	{
		if (i % 3 == 0)
		{
			nodes += Node();
			nodes[i / 3].N = text.GetIntInText()[i];
		}
		else if (i % 3 == 1)
		{
			nodes[i / 3].x = text.GetIntInText()[i];
		}
		else if (i % 3 == 2)
		{
			nodes[i / 3].y = text.GetIntInText()[i];
		}
		
	}
}


