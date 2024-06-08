#include "Euler3_LargestPrimeFactor.h"
#include <iostream>
#include <vector>

Euler3_LargestPrimeFactor::Euler3_LargestPrimeFactor()
{
}

Euler3_LargestPrimeFactor::~Euler3_LargestPrimeFactor()
{
}

std::string Euler3_LargestPrimeFactor::Name()
{
	return "Euler3 Largest Prime Factor";
}

void Euler3_LargestPrimeFactor::Run()
{
	long long inputNumber = 600851475143;
	std::cout << "Finding the prime factors of: " << inputNumber << std::endl;
	std::cin;

	std::vector<long long> primeList;
	
	//From wiki
	//https://en.wikipedia.org/wiki/Trial_division
	long long checkFactor = 2;
	long long count = 600851475143;
	while (count > 1)
	{
		if (count % checkFactor == 0)
		{
			std::cout << "" << count << " divides evenly with " << checkFactor << std::endl;

			primeList.push_back(checkFactor);
			count /= checkFactor;
		}
		else
		{
			checkFactor += 1;
		}
	}
	
	for (int i = 0; i < primeList.size(); i++)
	{
		std::cout << " " << primeList[i];
	}
}
