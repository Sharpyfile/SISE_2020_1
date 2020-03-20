#pragma once
#include "SearchStrategy.h"
#include "Graph.h"
#include "Node.h"

class BFSStrategy : public SearchStrategy
{
private:
	std::vector<puzzle> set;
	std::vector<Node *> queue;
public:
	BFSStrategy(Graph *, std::string);
	~BFSStrategy();

	bool search(int, puzzle, std::string&);
	bool checkIfVisited(puzzle);
	void checkIfReachedMax(int currentDepth);
};

