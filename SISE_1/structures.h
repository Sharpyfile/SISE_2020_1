#include <vector>
#pragma once

struct puzzle
{
	int sizeX;
	int sizeY;
	std::vector<int> puzzleState;
	int zeroAt;
};