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
	if (this->strategy->search(30, this->currentState, endResult))
		cout << "Found solution: " << endResult << endl;
	else
		cout << "e" << endl;
	

}


Graph::~Graph()
{
}

void Graph::moveZero(char direction)
{
	if (direction == 'L')
	{
		this->currentState = moveL(currentState);
	}		
	else if (direction == 'R')
	{
		this->currentState = moveR(currentState);
	}
	else if (direction == 'D')
	{
		this->currentState = moveD(currentState);
	}
	else if (direction == 'U')
	{
		this->currentState = moveU(currentState);
	}
}

void Graph::availableMoves(string & availableMoves)
{
	string tempMoves;

	if (!availableMoves.empty())
	{
		for (char s : availableMoves)
		{

			if (s == 'L')
			{
				if (checkMoveL(currentState))
					tempMoves += s;
			}				
			else if (s == 'R')
			{
				if (checkMoveR(currentState))
					tempMoves += s;
			}
			else if (s == 'D')
			{
				if (checkMoveD(currentState))
					tempMoves += s;
			}
			else if (s == 'U')
			{
				if (checkMoveU(currentState))
					tempMoves += s;
			}
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
		temp.puzzleState.push_back(i+1);

	temp.puzzleState.push_back(0);
	temp.sizeX = startState.sizeX;
	temp.sizeY = startState.sizeY;
	temp.zeroAt = startState.puzzleState.size() - 1;

	return temp;
}
