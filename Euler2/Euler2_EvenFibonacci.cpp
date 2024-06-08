#include "Euler2_EvenFibonacci.h"
#include <iostream>

Euler2_EvenFibonacci::Euler2_EvenFibonacci()
{
}

Euler2_EvenFibonacci::~Euler2_EvenFibonacci()
{
}

std::string Euler2_EvenFibonacci::Name()
{
	return "Euler2 Even Fibonacci";
}

void Euler2_EvenFibonacci::Run()
{	
	std::cout << "Set a max number to find the sum of all even fibonacci numbers: " << std::endl;
	int inputNumber = GetInputValue();

	int result = 0;
	int count1 = 2;
	int count2 = 3;

	int total = 0;

	
	while (count1 < inputNumber || count2 < inputNumber)
	{		
		if (count1 % 2 == 0)
		{
			std::cout << " " << count1;
			result += count1;
		}

		if (count2 % 2 == 0)
		{
			std::cout << " " << count2;
			result += count2;
		}

		count1 = count1 + count2;
		count2 = count2 + count1;
	}

	std::cout << std::endl << "Result number from " << inputNumber << " is " << result << std::endl;
}
