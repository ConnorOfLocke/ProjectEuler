#include "Euler20_FactorialDigitSum.h"

Euler20_FactorialDigitSum::Euler20_FactorialDigitSum()
{
}

Euler20_FactorialDigitSum::~Euler20_FactorialDigitSum()
{
}

std::string Euler20_FactorialDigitSum::Name()
{
	return "Euler 20 Factorial Digit Sum";
}

void Euler20_FactorialDigitSum::Run()
{
	int targetFactorial = 100;	
	std::string resultString = "1";
	for (int factorial = 1; factorial <= targetFactorial; factorial++)
	{		
		//Adds the number to itself however many times we're mulitplying it
		std::vector<std::string> inputBigNumbers;
		for (int i = 0; i < factorial; i++)
		{
			inputBigNumbers.push_back(resultString);
		}

		resultString = this->AddHugeNumbers(inputBigNumbers);

		printf("\n%d! value is: %s", factorial, resultString.c_str());
	}

	//sum answer
	long digitCount = 0;
	size_t resultNumberSize = resultString.size();
	for (int i = 0; i < resultNumberSize; i++)
	{
		digitCount += (resultString[i] - '0');
	}

	printf("\nOur final number iiiiiiiiiiss: %d", digitCount);

}
