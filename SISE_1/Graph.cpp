#include "Graph.h"

using namespace std;


Graph::Graph(puzzle startState, string strategyName, string orderOfSearch, string fileSolutionName, string filetatsName)
{
	this->startState = startState;
	this->currentState = startState;
	this->endState = createEndState();
	this->lastPosition = 'e';					//EEEEEEEEEEEE

	if (strategyName == "dfs")
		this->strategy = new DFSStrategy(this, orderOfSearch);
	else if (strategyName == "bfs")
		this->strategy = new BFSStrategy(this, orderOfSearch);

	string endResult;
	
	this->strategy->reachedDepth = 0;
	
	auto start = chrono::steady_clock::now();

	this->strategy->search(20, this->currentState, endResult);
	
	auto end = chrono::steady_clock::now();

	long long duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

	saveToFile(endResult, fileSolutionName, filetatsName, duration);
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

void Graph::saveToFile(string solution, string filename1, string filename2, long long duration)
{
	ofstream file1(filename1);

	if (solution.size() <= 0)
		file1 << -1;
	else
	{
		file1 << solution.size() << endl;
		file1 << solution;
	}

	file1.close();

	ofstream file2(filename2);
	if (solution.size() <= 0)
	{
		file2 << -1 << endl;

	}
	else
		file2 << solution.size() << endl;

	file2 << this->strategy->visited << endl;
	file2 << this->strategy->processed << endl;
	file2 << this->strategy->reachedDepth << endl;
	float finalDuration = (double)duration / 1000;
	file2 << finalDuration;

	file2.close();


}
