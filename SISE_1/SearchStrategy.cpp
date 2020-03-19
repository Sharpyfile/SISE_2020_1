#include "SearchStrategy.h"

SearchStrategy::SearchStrategy(Graph * graph, std::string orderOfSearch)
{
	this->graph = graph;
	this->orderOfSearch = orderOfSearch;
}


SearchStrategy::~SearchStrategy()
{
}
