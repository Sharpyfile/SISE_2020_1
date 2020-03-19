#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "Graph.h"

using namespace std;

puzzle loadPuzzleFromFile(string);

int main()
{
	puzzle puzzle1 = loadPuzzleFromFile("4x4_01_00001.txt");
	Graph * graph = new Graph(puzzle1, "dfs", "LDRU");
	getchar();
	return 0;
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


