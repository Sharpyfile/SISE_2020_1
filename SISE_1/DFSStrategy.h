#pragma once
#include"SearchStrategy.h"
#include "Graph.h"

class DFSStrategy : public SearchStrategy
{
private:
	std::vector<std::pair<puzzle, std::string>> map;
public:
	DFSStrategy(Graph *, std::string);
	~DFSStrategy();
	bool search(int, puzzle, std::string &);
	bool checkIfVisited(puzzle &, std::string &);
};

