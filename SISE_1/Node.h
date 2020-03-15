#pragma once
#include "structures.h"

class Node
{
private:	

	Node *parent;
	puzzle currentState;
	std::vector<Node *> children;
	int layer;
	int currentLayer;
	std::string type;
	bool parentFinished;
	

public:
	Node(Node *parent, puzzle currentState, int layer, std::string type);
	~Node();
	void addChildren();
	void nextLayer();
	void displayCurrentState();
	std::vector<Node *> getChildren();
	int getLayer();
	puzzle getCurrentState();
	bool checkIfStateOccured(std::vector<int> puzzleState);
	bool checkIfFoundSolution();
	bool parentFinishedCheching();
};

