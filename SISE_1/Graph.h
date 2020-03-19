#pragma once
#include "structures.h"
#include "SearchStrategy.h"
#include "DFSStrategy.h"
#include <iostream>
#include <string>

class Graph
{
public:

	puzzle currentState, startState, endState;
	char lastPosition;
	std::string currentPath;
	SearchStrategy * strategy;

	Graph(puzzle startState, string, string);
	puzzle createEndState();
	void moveZero(char);
	~Graph();
	void availableMoves(std::string &);

	

};

