#include "Graph.h"

using namespace std;


Graph::Graph(puzzle startState, string strategyName, string orderOfSearch)
{
	this->startState = startState;
	this->currentState = startState;
	this->endState = createEndState();
	this->lastPosition = 'e';					//EEEEEEEEEEEE

	if (strategyName == "dfs")
		this->strategy = new DFSStrategy(this, orderOfSearch);

	string endResult;
	this->strategy->search(30, this->currentState, endResult);
	cout << "Found solution: "<< endResult << endl;
	

}


Graph::~Graph()
{
}

void Graph::moveZero(char direction)
{
	if (direction == 'L')
	{
		moveL(currentState);
	}		
	else if (direction == 'R')
	{
		moveR(currentState);
	}
	else if (direction == 'D')
	{
		moveD(currentState);
	}
	else if (direction == 'U')
	{
		moveU(currentState);
	}
}

void Graph::availableMoves(string & availableMoves)
{
	string tempMoves = availableMoves;
	if (!tempMoves.empty())
	{
		for (char s : tempMoves)
		{
			if (s == 'L')
				if (!checkMoveL(currentState))
					tempMoves.erase(tempMoves.find(s), 1);
			if (s == 'R')
				if (!checkMoveR(currentState))
					tempMoves.erase(tempMoves.find(s), 1);
			if (s == 'D')
				if (!checkMoveD(currentState))
					tempMoves.erase(tempMoves.find(s), 1);
			if (s == 'U')
				if (!checkMoveU(currentState))
					tempMoves.erase(tempMoves.find(s), 1);
		}

		if (lastPosition == 'L' || lastPosition == 'R' || lastPosition == 'U' || lastPosition == 'D')
		{
			tempMoves.erase(tempMoves.find(lastPosition), 1);
		}
	}
	

	availableMoves = tempMoves;
}

puzzle Graph::createEndState()
{
	puzzle temp;
	for (int i = 0; i < startState.puzzleState.size() - 1; i++)
		temp.puzzleState.push_back(i);

	temp.puzzleState.push_back(0);
	temp.sizeX = startState.sizeX;
	temp.sizeY = startState.sizeY;
	temp.zeroAt = startState.puzzleState.size() - 1;

	return temp;
}
