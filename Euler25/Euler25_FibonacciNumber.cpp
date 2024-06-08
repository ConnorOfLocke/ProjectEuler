#include "Euler25_FibonacciNumber.h"
#include <iostream>

Euler25_FibonacciNumber::Euler25_FibonacciNumber()
{
}

Euler25_FibonacciNumber::~Euler25_FibonacciNumber()
{
}

std::string Euler25_FibonacciNumber::Name()
{
	return "Euler 25 Fibonacci Number";
}

void Euler25_FibonacciNumber::Run()
{
	int targetDigits = 1000;

	//Find the first fibonacci sequence with 1000 digits
	std::string firstValue = "1";
	std::string secondValue = "1";

	int index = 2;
	while (secondValue.size() < targetDigits)
	{
		std::string value = AddHugeNumbers(firstValue, secondValue);
		printf("\n%d-%s", index, value.c_str());		
		firstValue = secondValue;
		secondValue = value;
		index++;
	}

	printf("\n\nOur first number with %d digits is %s at index %d", targetDigits, secondValue.c_str(), index);


}
