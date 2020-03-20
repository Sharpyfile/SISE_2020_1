#pragma once
#include "structures.h"

class Node
{
public:
	Node(puzzle state);
	~Node();
	std::string currentPath;
	puzzle currentState;
};

