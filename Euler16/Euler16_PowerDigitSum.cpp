#include "Euler16_PowerDigitSum.h"
#include <iostream>

Euler16_PowerDigitSum::Euler16_PowerDigitSum()
{
}

Euler16_PowerDigitSum::~Euler16_PowerDigitSum()
{
}

std::string Euler16_PowerDigitSum::Name()
{
	return "Euler 16 Power Digit Sum";
}

void Euler16_PowerDigitSum::Run()
{
	//2^15 = 32768
	//3 + 2+ 7 + 6 + 8 = 26

	//what is the 1000s power sum of each digit

	int targetPower = 1000;
	std::string resultNumber = "2";

	printf("Starting our power calculations\n");
	for (int i = 0; i < targetPower - 1; i++)
	{
		std::string nextNumber = AddHugeNumbers({ resultNumber, resultNumber });
		std::cout << "2 to the power of " << (i + 2) << " comes to " << nextNumber << std::endl;
		resultNumber = nextNumber;		
	}

	long digitCount = 0;
	size_t resultNumberSize = resultNumber.size();
	for (int i = 0; i < resultNumberSize; i++)
	{		
		digitCount += resultNumber[i] - '0';
	}
	printf("\n All the digits added together make up: %ld", digitCount);
}
