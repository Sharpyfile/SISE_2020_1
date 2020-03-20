#pragma once
#include "structures.h"
#include "SearchStrategy.h"
#include "DFSStrategy.h"
#include "BFSStrategy.h"
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>

class Graph
{
public:

	puzzle currentState, startState, endState;
	char lastPosition;
	std::string currentPath;
	SearchStrategy * strategy;

	Graph(puzzle startState, string, string, string, string);
	puzzle createEndState();
	void moveZero(char);
	~Graph();
	void availableMoves(std::string &);
	void saveToFile(string, string, string, long long);

};

