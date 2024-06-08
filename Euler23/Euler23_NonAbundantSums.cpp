#include "Euler23_NonAbundantSums.h"
#include <iostream>
#include <map>

Euler23_NonAbundantSums::Euler23_NonAbundantSums()
{
}

Euler23_NonAbundantSums::~Euler23_NonAbundantSums()
{
}

std::string Euler23_NonAbundantSums::Name()
{
	return "Euler 23 Non-Abundant Sums";

}

void Euler23_NonAbundantSums::Run()
{
	//An abundant number is a number where the sum of divisors are greater than the number
	//SO 12 - 1 + 2+3+4+6 = 16 which 16 > 12

	//24 is the smallest number that can be represented by the sum of two abundant numbers

	//All integers > 28123 can be written as the sum of 2 abundant numbers
	//Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

	const int abundantMin = 12;
	const int abundantMax = 28123;

	//Make a list of all the abundant numbers < 0.5 * abundantmax

	std::vector<int> abundantNums = {  };
	std::map<int, int> sums;

	std::vector<int> factors;
	long abundantSum = 0;

	for (int checkNum = 1; checkNum <= abundantMax; checkNum++)
	{
		//check we have factors
		factors = GetFactors(checkNum);
		size_t factorSize = factors.size();
		int factSum = 0;
		for (int i = 0; i < factorSize; i++)
		{
			factSum += factors[i];
		}

		if (factSum > checkNum)
		{
			abundantNums.push_back(checkNum);
			//check it against the other abundant numbers
			size_t size = abundantNums.size();
			for (int checkAbundIndex = 0; checkAbundIndex < size; checkAbundIndex++)
			{
				int sum = abundantNums[size - 1] + abundantNums[checkAbundIndex];				
				sums[sum] = 1;				
			}
		}

		//Non abundant
		if (sums[checkNum] == 0)
		{
			printf("\nFound target non abund number: %d",  checkNum);
			abundantSum += checkNum;
		}
	}

	printf("\n\nFinal sum of all non abundant ints: %d", abundantSum);

	/*printf("\nAbundant numbers we found are: ");
	int abundantNums_size = abundantNums.size();
	for (int i = 0; i < abundantNums_size; i++)
	{
		std::cout << abundantNums[i] << " ";
	}*/
	
}
