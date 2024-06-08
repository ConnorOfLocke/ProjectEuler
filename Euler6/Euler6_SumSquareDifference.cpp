#include "Euler6_SumSquareDifference.h"
#include <iostream>

Euler6_SumSquareDifference::Euler6_SumSquareDifference()
{
}

Euler6_SumSquareDifference::~Euler6_SumSquareDifference()
{
}

std::string Euler6_SumSquareDifference::Name()
{
	return "Euler 6 Sum Square Difference";
}

void Euler6_SumSquareDifference::Run()
{
	std::cout << "Set a max number to find the smallest multiple between it and 1: " << std::endl;
	int inputNumber = GetInputValue();

	//find the sum of squares up the input value
	long long squareSum = 0;
	long long sumOfSquares = 0;
	/*for (int i = 1; i <= inputNumber; i++)
	{
		squareSum += i * i;
		sumOfSquares += i;
	}
	sumOfSquares = sumOfSquares * sumOfSquares;
	*/

	//After looking at other solutions
	//sumOfSquares = (n(n+1)/2)^2
	//squareSum = n(n+1)(2n+1)/6
	sumOfSquares = inputNumber * (inputNumber + 1) / 2;
	sumOfSquares = sumOfSquares * sumOfSquares;
	squareSum = inputNumber * (inputNumber + 1) * (2 * inputNumber + 1) / 6;
	
	std::cout << "SquareSum: " << squareSum << " - Sum Of Squares: " << sumOfSquares << std::endl;
	std::cout << "Difference : " << (sumOfSquares - squareSum) << std::endl;

}
