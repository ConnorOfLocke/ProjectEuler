#include "Euler26_ReciprocalCycles.h"
#include <iostream>

Euler26_ReciprocalCycles::Euler26_ReciprocalCycles()
{
}

Euler26_ReciprocalCycles::~Euler26_ReciprocalCycles()
{
}

std::string Euler26_ReciprocalCycles::Name()
{
	return "Euler 26 Reciprocal Cycles";
}

void Euler26_ReciprocalCycles::Run()
{
	// 1/6 - 0.1(6) recuring has 1 digit repeating
	// 1/7 - 0.(142857) has 6 digits repeating
	//Find the longest recurring digit part between 1 and 1/1000

	int maxValue = 10000;

	std::string largestPattern = "";
	std::string largestResult = "";
	int largestDenominator = 0;
	size_t largestSize = 0;

	//After solving, found out only the primes are worth testing
	//Primes will give the same number of repeating values as its lower prime factor
	std::vector<long> primes = GeneratePrimes(maxValue);
	int primesSize = primes.size();
	for (int primeindex = 1; primeindex < primesSize; primeindex++)
	{
		int denominator = primes[primeindex];

		std::string result = "";
		std::string repeatPattern = "";

		bool foundValue = false;
		bool evenDivisible = false;
		int value = 10; //skipping the 0. 

		std::vector<int> pastRemainders;
		std::vector<int> pastDivisions;

		while (!foundValue)
		{
			int remainder = value % denominator;
			int division = value / denominator;

			result += std::to_string(division);

			//evenly divisible
			if (remainder == 0)
			{
				foundValue = true;		
				evenDivisible = true;
				break;
			}			

			if (remainder >= 0)
			{								
				//check we have a repeat	
				size_t opsSoFar = pastDivisions.size();
				for (int i = opsSoFar - 1; i >= 0; i--)
				{
					//we've come this way before
					if (remainder == pastRemainders[i] &&
						division == pastDivisions[i])
					{
						repeatPattern = result.substr(i, opsSoFar - i);
						foundValue = true;
						break;
					}
				}
				
				pastDivisions.push_back(division);
				pastRemainders.push_back(remainder);
				value = remainder;
			}
			value *= 10;
		}		
			
		if (evenDivisible)		
			printf("\n(1 / %d) evenly divides = 0.%s", denominator, result.c_str());
		else
			printf("\n(1 / %d) repeats = 0.%s with pattern (%s)", denominator, result.c_str(), repeatPattern.c_str());

		if (repeatPattern.size() > largestSize)
		{
			largestPattern = repeatPattern;
			largestResult = result;
			largestDenominator = denominator;
			largestSize = repeatPattern.size();
		}
	}

	printf("\n\nFinal largest value found is (1 / %d) = %s with pattern %s", largestDenominator, largestResult.c_str(), largestPattern.c_str());

}

//dont need it
/*
bool Euler26_ReciprocalCycles::FindRepeatingPattern(std::string const& input, std::string& output)
{
	size_t inputStringSize = input.size();
	output = "";

	//for values like 0.16666666666 etc
	for (int startingIndex = 0; startingIndex < inputStringSize; startingIndex++)
	{
		for (int checkSize = 1; startingIndex + checkSize < inputStringSize; checkSize++)
		{
			std::string checkString = input.substr(startingIndex, checkSize);

			int correctCount = (inputStringSize - startingIndex) / checkSize - 1;			
			if (correctCount < 1)
				continue;

			int repeatCount = 0;
			
			for (int i = 1; checkSize * i < inputStringSize; i++)
			{
				std::string nextCheckString = input.substr(startingIndex + (checkSize * i), checkSize);
				if (checkString.compare(nextCheckString) == 0)
				{
					repeatCount++;
				}
				else
				{
					break;
				}
			}

			if (repeatCount >= correctCount)
			{
				output = checkString;
				break;
			}

		}
	}

	return output != "";
}*/
