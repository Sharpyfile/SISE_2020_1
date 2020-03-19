#pragma once
#include "structures.h"

class Node
{
private:	
	std::string currentPath;
	puzzle currentState;
	

public:
	Node(puzzle state);
	~Node();
};

