#include "Node.h"

using namespace std;

Node::Node(Node *parent, puzzle puzzleState, int layer, string type)
{
	this->parent = parent;
	this->currentState = puzzleState;
	this->layer = layer;
	this->type = type;
	if (parent == nullptr)
	{
		parentFinished = true;
	}
	else
		this->parentFinished = false;
	
	if (type == "dfs")
	{
		if (checkIfFoundSolution())
		{
			cout << "Found solution" << endl;
			this->displayCurrentState();
			getchar();
			exit(0); // do zmiany
		}
		else
		{
			this->addChildren();
		}
	}
	else if (type == "bfs")
	{
		if (checkIfFoundSolution())
		{
			cout << "Found solution" << endl;
			this->displayCurrentState();
			getchar();
			exit(0); // do zmiany
		}
	}		
}


Node::~Node()
{

}

void Node::addChildren()
{
	if (this->layer + 1 < 20)
	{
		if (moveR(this->currentState).zeroAt != -1)
		{
			if (this->checkIfStateOccured(moveR(this->currentState).puzzleState) == false)
			{
				Node *right = new Node(this, moveR(this->currentState), this->layer + 1, this->type);
				children.push_back(right);
			}

		}

		if (moveL(this->currentState).zeroAt != -1)
		{
			if (this->checkIfStateOccured(moveL(this->currentState).puzzleState) == false)
			{
				Node *left = new Node(this, moveL(this->currentState), this->layer + 1, this->type);
				children.push_back(left);
				
			}

		}		

		if (moveD(this->currentState).zeroAt != -1)
		{
			if (this->checkIfStateOccured(moveD(this->currentState).puzzleState) == false)
			{
				Node *down = new Node(this, moveD(this->currentState), this->layer + 1, this->type);
				children.push_back(down);
			}

		}

		if (moveU(this->currentState).zeroAt != -1)
		{

			if (this->checkIfStateOccured(moveU(this->currentState).puzzleState) == false)
			{
				Node *up = new Node(this, moveU(this->currentState), this->layer + 1, this->type);
				children.push_back(up);
			}
		}
			   	
	}
	
}

void Node::nextLayer()
{
	if (layer == 0)
	{
		this->currentLayer = 1;
		this->addChildren();
		for (Node * node : this->getChildren())
		{
			checkIfSolved(node->getCurrentState());
			node->addChildren();
		}

	}
}


void Node::displayCurrentState()
{
	cout << "Current Layer: " << this->getLayer() << endl;
	displayCurrentPuzzleState(this->currentState);
}

std::vector<Node *> Node::getChildren()
{
	return this->children;
}

int Node::getLayer()
{
	return this->layer;
}

puzzle Node::getCurrentState()
{
	return this->currentState;
}

bool Node::checkIfStateOccured(std::vector<int> puzzleState)
{
	if (parent != nullptr)
	{
		if (parent->getCurrentState().puzzleState == puzzleState)
			return true;
		else
			return parent->checkIfStateOccured(puzzleState);
	}
	else
		return false;
}

bool Node::checkIfFoundSolution()
{

	return checkIfSolved(this->getCurrentState());

	
}

bool Node::parentFinishedCheching()
{
	return this->parentFinished;
}