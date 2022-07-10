#pragma once

#include "DataStructure/Vector.h"
#include "Text.h"

struct Node
{
	Node() {}
	Node(const int& N, const int& x, const int& y) : N(N), x(x), y(y) {}

	int N = 0;			// the number of coordinates 
	int x = 0, y = 0;
};

struct Line
{
	Line() {}
	Line(const Node& n1, const Node& n2) : n1(n1), n2(n2), distance(GetNodeDistance(n1, n2)) {}
	
	const double& GetNodeDistance(const Node& n1, const Node& n2);
	
	Node n1;
	Node n2;
	double distance = 0;
};

class Problem3
{
public:
	Problem3(std::string filepath);
	~Problem3() {}

private:
	void SetNodes();
	
	Text text;
	std::string filepath;
	Vector<Node> nodes;
	Vector<Line> lines;
};
