#include "DFSStrategy.h"


using namespace std;

DFSStrategy::DFSStrategy(Graph *graph, string orderOfSearch) : SearchStrategy(graph, orderOfSearch)
{

}


DFSStrategy::~DFSStrategy()
{

}

bool DFSStrategy::search(int steps, puzzle state, string &path)
{
	if (graph->endState.puzzleState == state.puzzleState)
	{
		this->checkIfReachedMax(path.size());
		this->processed = this->visited;
		return true;
	}		
	else if (path.size() < steps)
	{
		this->checkIfReachedMax(path.size());
		this->map.push_back({ state, path });
		graph->currentState = state;

		if (!path.empty())
		{
			if (path.back() == 'L')
				graph->lastPosition = 'R';
			else if (path.back() == 'R')
				graph->lastPosition = 'L';
			else if (path.back() == 'U')
				graph->lastPosition = 'D';
			else if (path.back() == 'D')
				graph->lastPosition = 'U';
		}
		

		string tempOrderOfSearch = orderOfSearch;		
		graph->availableMoves(tempOrderOfSearch);
		
		while (!tempOrderOfSearch.empty())
		{
			graph->currentState = state;
			graph->moveZero(tempOrderOfSearch.at(0));
			path += tempOrderOfSearch.at(0);
			tempOrderOfSearch.erase(0, 1);
			if (!checkIfVisited(graph->currentState, path))
			{
				this->visited++;
				if (search(steps, graph->currentState, path))
					return true;
			}
				
			

			path.pop_back();

		}
	}

	return false;
}

bool DFSStrategy::checkIfVisited(puzzle &state, string &path)
{
	int iterator = 0;

	for (int i = 0; i < this->map.size(); i++)
	{
		if (this->map.at(i).first.puzzleState == state.puzzleState)
		{
			iterator = i;
			break;
		}
		
	}
	if (!this->map.at(iterator).second.empty())
	{
		if (this->map.at(iterator).first.puzzleState == this->map.back().first.puzzleState &&
			this->map.at(iterator).second == this->map.back().second)
		{

			return false;
		}
		else if (this->map.at(iterator).second.size() <= path.size())
		{

			return true;
		}
		else
		{
			this->map.at(iterator).second = path;
			return false;
		}
	}
	
	return false;	
}

void DFSStrategy::checkIfReachedMax(int currentDepth)
{
	if (currentDepth > this->reachedDepth)
		this->reachedDepth = currentDepth;
}