#pragma once
#include "Node.h"

class Graph;

class SearchStrategy
{
public:
	SearchStrategy(Graph *, std::string);
	Graph * graph;
	std::string orderOfSearch;
	virtual ~SearchStrategy();
	virtual bool search(int, puzzle, std::string &) = 0;
};

