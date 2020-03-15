#include <vector>
#include <iostream>
#include <iomanip>

#pragma once

struct puzzle
{
	int sizeX;
	int sizeY;
	std::vector<int> puzzleState;
	int zeroAt;
};

bool checkMoveL(puzzle);
puzzle moveL(puzzle);
bool checkMoveR(puzzle);
puzzle moveR(puzzle);
bool checkMoveU(puzzle);
puzzle moveU(puzzle);
bool checkMoveD(puzzle);
puzzle moveD(puzzle);
bool checkIfSolved(puzzle);
void displayCurrentPuzzleState(puzzle);