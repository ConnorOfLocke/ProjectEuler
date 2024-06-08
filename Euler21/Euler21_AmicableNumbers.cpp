#include "Euler21_AmicableNumbers.h"
#include <map>
#include <algorithm>

Euler21_AmicableNumbers::Euler21_AmicableNumbers()
{
}

Euler21_AmicableNumbers::~Euler21_AmicableNumbers()
{
}

std::string Euler21_AmicableNumbers::Name()
{
	return "Euler21 Amicable Numbers";
}

void Euler21_AmicableNumbers::Run()
{
	//D(n) = Sum of the divisors of n
	//eg
	//  D(220) = 1 + 2+4+5+10+11+20+22+44+55+110 = 284
	//  D(284) = 1 + 2+4+71+142 = 220
	//  220 and 284 are amicable pairs

	//find all the amicable pairs under 10000
	//add them togther

	int targetNumber = 10000;

	// go through each number, store the sum of thier factors
	std::vector<int> factorSums;
	for (int i = 0; i < targetNumber; i++)
	{
		std::vector<int> factors = GetFactors(i + 1);
		int factorSum = 0;
		int factorSize = (int)factors.size();
		for (int i = 0; i < factorSize; i++)
		{
			factorSum += factors[i];
		}		

		factorSums.push_back(factorSum);
	}
	printf("\nCalcuated the factor sums");

	std::map<int, int> amicablePairIndexs; 
	// check each number below them and above them
	// (We likely don't need to check higher than 1.5 times the number)
	for (int checkFactorIndex = 0; checkFactorIndex < targetNumber; checkFactorIndex++)
	{
		//check we dont already have this number
		if (amicablePairIndexs.find(checkFactorIndex) != amicablePairIndexs.end())
			continue;

		int maxIndex = std::min((int)(checkFactorIndex * 1.5), targetNumber);
		for (int i = 0; i < maxIndex; i++)
		{
			if (factorSums[checkFactorIndex] == (i + 1) &&
				factorSums[i] == (checkFactorIndex + 1) &&
				checkFactorIndex != i)
			{
				amicablePairIndexs[checkFactorIndex] = i;
				amicablePairIndexs[i] = checkFactorIndex;
				break;
			}
		}
	}

	printf("\n Found all the pairs");
	int total = 0;
	//Add all the numbers
	for( const auto& pair : amicablePairIndexs)
	{
		printf("\nPair: %d and %d", pair.first + 1, pair.second + 1);		
		total += pair.first + 1;
	}
	
	printf("\n\nFinal Sum!: %d ", total);
}
