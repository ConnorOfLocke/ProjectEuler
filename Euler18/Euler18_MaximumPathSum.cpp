#include "Euler18_MaximumPathSum.h"
#include <map>

Euler18_MaximumPathSum::Euler18_MaximumPathSum()
{
}

Euler18_MaximumPathSum::~Euler18_MaximumPathSum()
{
}

std::string Euler18_MaximumPathSum::Name()
{
	return "Euler18 Maximum Path Sum";
}

void Euler18_MaximumPathSum::Run()
{
	std::vector< std::vector<int>> inputTriangle = {
		{75},
		{95, 64, },
		{17, 47, 82},
		{18, 35, 87, 10},
		{20, 04, 82, 47, 65},
		{19, 01, 23, 75, 03, 34},
		{88, 02, 77, 73, 07, 63, 67},
		{99, 65, 04, 28, 06, 16, 70, 92},
		{41, 41, 26, 56, 83, 40, 80, 70, 33},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
		{63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
		{04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23} };
	
	size_t rowCount = inputTriangle.size();
	
	//Setup the spot to store all the totals
	std::vector<std::vector<int>> triangleTotals;
	for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
	{
		std::vector<int> newRow;
		for (int i = 0; i < inputTriangle[rowIndex].size(); i++)
		{
			newRow.push_back(0);
		}
		triangleTotals.push_back(newRow);
	}

	triangleTotals[0][0] = inputTriangle[0][0];

	//Work through each 
	for (int rowIndex = 1; rowIndex < rowCount; rowIndex++)
	{
		for (int i = 0; i < triangleTotals[rowIndex].size(); i++)
		{
			int leftSum = 0;
			int rightSum = 0;

			//check left
			if (i - 1 >= 0)
				leftSum = inputTriangle[rowIndex][i] + triangleTotals[rowIndex - 1][i - 1];

			//check right
			if (i < triangleTotals[rowIndex - 1].size())
				rightSum = inputTriangle[rowIndex][i] + triangleTotals[rowIndex - 1][i];

			//take the highest of the two
			triangleTotals[rowIndex][i] = (leftSum > rightSum) ? leftSum : rightSum;
		}
	}

	int highestSum = 0;
	//Check the highest of the last row
	for (int i = 0 ; i < triangleTotals[rowCount - 1].size(); i++)
	{
		if (triangleTotals[rowCount - 1][i] > highestSum)
			highestSum = triangleTotals[rowCount - 1][i];
	}

	printf("\nThe highest possible value from top to bottom is: %d", highestSum);
}
