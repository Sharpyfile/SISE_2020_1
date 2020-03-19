#include "structures.h"

using namespace std;

bool checkMoveL(puzzle passedPuzzle)
{
	if ((passedPuzzle.zeroAt - 1) % passedPuzzle.sizeX == passedPuzzle.sizeX - 1 || (unsigned int)(passedPuzzle.zeroAt - 1) == -1)
		return false;
	else
		return true;
}


puzzle moveL(puzzle passedPuzzle)												 //move left
{
	if (checkMoveL(passedPuzzle))
	{
		swap(passedPuzzle.puzzleState.at(passedPuzzle.zeroAt), passedPuzzle.puzzleState.at(passedPuzzle.zeroAt - 1));
		passedPuzzle.zeroAt -= 1;
		return passedPuzzle;
	}
	else
	{
		puzzle puzzleError;
		puzzleError.zeroAt = -1;
		return puzzleError;
	}

}

bool checkMoveR(puzzle passedPuzzle)
{
	if ((passedPuzzle.zeroAt + 1) % passedPuzzle.sizeX == 0)
		return false;
	else
		return true;
}

puzzle moveR(puzzle passedPuzzle)												 //move right
{
	if (checkMoveR(passedPuzzle))
	{
		swap(passedPuzzle.puzzleState.at(passedPuzzle.zeroAt), passedPuzzle.puzzleState.at(passedPuzzle.zeroAt + 1));
		passedPuzzle.zeroAt += 1;
		return passedPuzzle;
	}
	else
	{
		puzzle puzzleError;
		puzzleError.zeroAt = -1;
		return puzzleError;
	}

}

bool checkMoveU(puzzle passedPuzzle)
{
	
	if (passedPuzzle.zeroAt - passedPuzzle.sizeY < 0)
		return false;

	else
		return true;
		
}

puzzle moveU(puzzle passedPuzzle)												 //move up
{
	if (checkMoveU(passedPuzzle))
	{
		swap(passedPuzzle.puzzleState.at(passedPuzzle.zeroAt), passedPuzzle.puzzleState.at(passedPuzzle.zeroAt - passedPuzzle.sizeY));
		passedPuzzle.zeroAt -= passedPuzzle.sizeY;
		return passedPuzzle;
	}
	else
	{
		puzzle puzzleError;
		puzzleError.zeroAt = -1;
		return puzzleError;
	}


}

bool checkMoveD(puzzle passedPuzzle)
{
	if (passedPuzzle.zeroAt + passedPuzzle.sizeY < passedPuzzle.sizeY * passedPuzzle.sizeX)
		return true;
	else
		return false;
}

puzzle moveD(puzzle passedPuzzle)												 //move down
{
	if (checkMoveD(passedPuzzle))
	{
		swap(passedPuzzle.puzzleState.at(passedPuzzle.zeroAt), passedPuzzle.puzzleState.at(passedPuzzle.zeroAt + passedPuzzle.sizeY));
		passedPuzzle.zeroAt += passedPuzzle.sizeY;
		return passedPuzzle;
	}
	else
	{
		puzzle puzzleError;
		puzzleError.zeroAt = -1;
		return puzzleError;
	}


}

bool checkIfSolved(puzzle passedPuzzle)
{
	for (int i = 1; i < 16; i++)
		if (passedPuzzle.puzzleState.at(i - 1) != i)
			return false;

	return true;

}

void displayCurrentPuzzleState(puzzle passedPuzzle)
{
	for (int i = 0; i < passedPuzzle.sizeX; i++)
	{
		for (int j = 0; j < passedPuzzle.sizeY; j++)
			cout << setw(3) << passedPuzzle.puzzleState.at(i * passedPuzzle.sizeX + j) << ' ';
		cout << endl;
	}
	cout << endl;
}