#include "Euler5_SmallestMultiple.h"
#include <iostream>

Euler5_SmallestMultiple::Euler5_SmallestMultiple()
{
}

Euler5_SmallestMultiple::~Euler5_SmallestMultiple()
{
}

std::string Euler5_SmallestMultiple::Name()
{
	return "Euler5 Smallest Multiple";
}

void Euler5_SmallestMultiple::Run()
{	
	std::cout << "Set a max number to find the smallest multiple between it and 1: " << std::endl;
	int inputNumber = GetInputValue();

	long long smallestLCM = 1;
	for (int maxFactor = 1; maxFactor < inputNumber; maxFactor++)
	{
		long long checkMultiple = 0;
		bool found = false;

		while (!found)
		{
			found = true;
			checkMultiple += smallestLCM;
			for (int checkFactor = maxFactor + 1; checkFactor > 1; checkFactor--)
			{
				if (checkMultiple % checkFactor != 0)
				{
					found = false;
					break;
				}
			}
		}

		std::cout << "Smallest LCM of factors 1 to " << maxFactor + 1 << " is " << checkMultiple  << std::endl;
		smallestLCM = checkMultiple;		
	}
}
