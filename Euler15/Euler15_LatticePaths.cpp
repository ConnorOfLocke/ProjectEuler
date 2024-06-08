#include "Euler15_LatticePaths.h"
#include <vector>

Euler15_LatticePaths::Euler15_LatticePaths()
{
}

Euler15_LatticePaths::~Euler15_LatticePaths()
{
}

std::string Euler15_LatticePaths::Name()
{
	return "Euler 15 Lattice Paths";
}

void Euler15_LatticePaths::Run()
{
	//Think less lattice graph more a decision tree
	
	// grid 1 is 2
	// grid 2 is 6
	// grid 3 is 20
	
	int gridSize = 20;
	int actualGridSize = gridSize + 1;
	int nodeCount = actualGridSize * actualGridSize;

	std::vector<long long> nodes;
	for (int i = 0; i < nodeCount; i++)
	{
		nodes.push_back(false);
	}
	
	nodes[0] = 1;

	//Walks through the grid and adds togther
	//how many times it's neighbor above and to the left of it has been visited
	for (int column = 0; column < actualGridSize; column++)
	{
		for (int row = 0; row < actualGridSize; row++)
		{
			//Left
			if (column > 0)
			{
				nodes[column + (row * actualGridSize)] += nodes[(column - 1) + (row * actualGridSize)];
			}
			//above
			if (row > 0)
			{
				nodes[column + (row * actualGridSize)] += nodes[(column)  + ((row - 1) * actualGridSize)];
			}
		}
	}

	// The last number cumulates into the total paths	
	printf("\nPathCount for a grid of %d is: %lld", gridSize, nodes[nodeCount - 1]);
}
