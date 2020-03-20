#include "BFSStrategy.h"
using namespace std;

BFSStrategy::BFSStrategy(Graph * graph, string orderOfSearch) : SearchStrategy(graph, orderOfSearch)
{

}


BFSStrategy::~BFSStrategy()
{

}

bool BFSStrategy::search(int steps, puzzle currentState, string& path)
{
	Node *node, *adjNode;
	
	string tempPath = path;

	node = new Node(graph->currentState);
	queue.push_back(node);
	set.push_back(node->currentState);


	while (!queue.empty())
	{
		node = queue.at(0);
		tempPath = node->currentPath;
		queue.erase(queue.begin(), queue.begin() + 1);
		
		if (graph->endState.puzzleState == node->currentState.puzzleState)
		{
			graph->currentState = node->currentState;
			path = node->currentPath;
			queue.erase(queue.begin());
			this->processed = this->visited;
			return true;
		}
		else if (tempPath.size() < steps)
		{
			graph->currentState = node->currentState;

			if (!node->currentPath.empty())
			{
				if (node->currentPath.back() == 'L')
					graph->lastPosition = 'R';
				else if (node->currentPath.back() == 'R')
					graph->lastPosition = 'L';
				else if (node->currentPath.back() == 'U')
					graph->lastPosition = 'D';
				else if (node->currentPath.back() == 'D')
					graph->lastPosition = 'U';
			}

			string tempOrderOfSearch = orderOfSearch;
			graph->availableMoves(tempOrderOfSearch);

			while (!tempOrderOfSearch.empty())
			{
				graph->currentState = node->currentState;
				tempPath += tempOrderOfSearch.at(0);
				graph->moveZero(tempOrderOfSearch.at(0));
				adjNode = new Node(graph->currentState);
				adjNode->currentPath = tempPath;
				tempOrderOfSearch.erase(0, 1);
				if (!checkIfVisited(adjNode->currentState))
				{
					set.push_back(adjNode->currentState);
					queue.push_back(adjNode);
				}
				else
				{
					this->visited++;
					delete adjNode;
				}
					
				this->checkIfReachedMax(tempPath.size());
				tempPath.pop_back();

			}

		}
		delete node;
	}

	this->processed = this->visited;
	return false;
}

bool BFSStrategy::checkIfVisited(puzzle state)
{
	for (int i = 0; i < set.size(); i++)
	{
		if (set.at(i).puzzleState == state.puzzleState)
			return true;
	}
	return false;
}

void BFSStrategy::checkIfReachedMax(int currentDepth)
{
	if (currentDepth > this->reachedDepth)
		this->reachedDepth = currentDepth;
}