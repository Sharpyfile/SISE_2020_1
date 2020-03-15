#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "structures.h"
using namespace std;

puzzle loadPuzzleFromFile(string);
void displayCurrentPuzzleState(puzzle);
void moveL(puzzle *);
void moveR(puzzle *);
void moveU(puzzle *);
void moveD(puzzle *);

int main()
{
	
	puzzle puzzle1 = loadPuzzleFromFile("4x4_01_00001.txt");
	cout << puzzle1.sizeX << endl;
	cout << puzzle1.sizeY << endl;
	cout << puzzle1.zeroAt << endl;
	cout << endl;


	displayCurrentPuzzleState(puzzle1);

	moveU(&puzzle1);
	displayCurrentPuzzleState(puzzle1);

	moveL(&puzzle1);
	displayCurrentPuzzleState(puzzle1);

	moveR(&puzzle1);
	displayCurrentPuzzleState(puzzle1);

	moveD(&puzzle1);
	displayCurrentPuzzleState(puzzle1);


	getchar();
	return 0;
}

void displayCurrentPuzzleState(puzzle puzzle)
{
	for (int i = 0; i < puzzle.sizeX; i++)
	{
		for (int j = 0; j < puzzle.sizeY; j++)
			cout << setw(3) << puzzle.puzzleState.at(i * puzzle.sizeX + j) << ' ';
		cout << endl;
	}
	cout << endl;
	
}

puzzle loadPuzzleFromFile(string filename)
{
	string dataFromFile;												//loading file

	ifstream file(filename, ifstream::binary);
	file.seekg(0, file.end);
	int length = file.tellg();
	file.seekg(0, file.beg);

	for (string line; getline(file, line); )							//dividing file into lines
	{
		if (!line.empty())
		{
			line.pop_back();
			dataFromFile += line + ' ';
		}
	}
	file.close();

	puzzle puzzle;	
	
	puzzle.sizeX = stoi(dataFromFile.substr(0, dataFromFile.find(' '))); //extracting sizeX
	dataFromFile.erase(0, dataFromFile.find(' ') + 1);					 //removing substring
	puzzle.sizeY = stoi(dataFromFile.substr(0, dataFromFile.find(' '))); //extracting sizeY
	dataFromFile.erase(0, dataFromFile.find(' ') + 1);					 //removing substring


	int size = puzzle.sizeX * puzzle.sizeY;

	for (int i = 0; i < size; i++)										 //dividing substring into numbers
	{
		int state = stoi(dataFromFile.substr(0, dataFromFile.find(' ')));
		puzzle.puzzleState.push_back(state);
		if (state == 0)
			puzzle.zeroAt = puzzle.puzzleState.size() - 1;
		dataFromFile.erase(0, dataFromFile.find(' ') + 1);		
	}

	return puzzle;														 //return puzzleStruct
}

void moveL(puzzle *puzzle)												 //move left
{
	cout << "Left" << endl;
	swap(puzzle->puzzleState.at(puzzle->zeroAt), puzzle->puzzleState.at(puzzle->zeroAt - 1));
	puzzle->zeroAt -= 1;
}

void moveR(puzzle *puzzle)												 //move right
{
	cout << "Right" << endl;
	swap(puzzle->puzzleState.at(puzzle->zeroAt), puzzle->puzzleState.at(puzzle->zeroAt + 1));
	puzzle->zeroAt += 1;
}

void moveU(puzzle *puzzle)												 //move up
{
	cout << "Up" << endl;
	swap(puzzle->puzzleState.at(puzzle->zeroAt), puzzle->puzzleState.at(puzzle->zeroAt - puzzle->sizeY));
	puzzle->zeroAt -= puzzle->sizeY;
}

void moveD(puzzle *puzzle)												 //move down
{
	cout << "Down" << endl;
	swap(puzzle->puzzleState.at(puzzle->zeroAt), puzzle->puzzleState.at(puzzle->zeroAt + puzzle->sizeY));
	puzzle->zeroAt += puzzle->sizeY;
}