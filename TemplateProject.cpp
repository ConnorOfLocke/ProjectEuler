#include "TemplateProject.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

int TemplateProject::GetInputValue()
{
	std::string input;
	std::cin >> input;

	int inputNumber = 0;
	try {
		inputNumber = std::stoi(input);
	}
	catch (...)
	{
		std::cout << "Invalid input : " << input;
		return 0;
	}
	return inputNumber;
}

std::vector<long> TemplateProject::GeneratePrimes(const long _upperBound)
{	
	long checkFactor = 2;

	std::vector<long> primeList;
	primeList.push_back(2);
	primeList.push_back(3);
	primeList.push_back(5);
	primeList.push_back(7);
	for (int i = 3; i < _upperBound; i+=2)
	{
		//slice out some common primes to save some time
		if (i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
		{
			primeList.push_back(i);
		}
	}

	//Sieve of Eratosthenes method
	int primeSize = (int)primeList.size();
	for (int factorIndex = 4; factorIndex < primeSize / 2; factorIndex++)
	{				
		for (int i = factorIndex + 1; i < primeSize; i++)
		{
			if (primeList[i] % primeList[factorIndex] == 0)
			{
				primeList.erase(primeList.begin() + i);
				i--;
				primeSize--;
			}
		}
	}		
	return primeList;	
}

std::string TemplateProject::AddHugeNumbers(const std::string input1, const std::string input2)
{
	std::vector<std::string> input{ input1, input2 };
	return AddHugeNumbers(input);
}

std::string TemplateProject::AddHugeNumbers(const std::vector<std::string> inputNumbers)
{
	//Odd way of calculating the size of the array of strings
	size_t inputNumberCount = inputNumbers.size();

	//get the largest string size
	int largestStringSize = 0;
	for (int i = 0; i < inputNumberCount; i++)
	{
		if (inputNumbers[i].size() > largestStringSize)
		{
			largestStringSize = (int)inputNumbers[i].size();
		}
	}

	std::vector<long> digits;
	//go through each string backwards and add all the digits together
	for (int digitIndex = 0; digitIndex < (int)largestStringSize; digitIndex++)
	{
		int digitTotal = 0;
		for (int i = 0; i < inputNumberCount; i++)
		{
			int charIndex = ((int)inputNumbers[i].size() - 1) - digitIndex;
			if (charIndex >= 0)
			{
				digitTotal += (inputNumbers[i][charIndex] - '0');
			}
		}

		digits.push_back(digitTotal);
	}

	//Then propagate it back
	for (int digitIndex = 0; digitIndex < largestStringSize; digitIndex++)
	{
		int digitOffset = 1;
		int column = 10;

		while (digits[digitIndex] >= column)
		{
			if (digits.size() <= digitIndex + digitOffset)
			{
				digits.push_back(0);
				largestStringSize++;
			}
			int check = (digits[digitIndex] / column) % column;
			digits[digitIndex + digitOffset] += check;

			digitOffset++;
			column *= 10;
		}

		digits[digitIndex] = digits[digitIndex] % 10;
	}

	//reverse the string back
	std::stringstream outputString;
	size_t digitSize = digits.size();
	for (int i = (int)digitSize-1; i >= 0; i--)
	{
		outputString << digits[i];
	}
	
	return outputString.str();
}

std::vector<int> TemplateProject::GetFactors(const int _inputNumber)
{
	std::vector<int> returnList;
	returnList.push_back(1);

	for (int checkFactor = 2; checkFactor <= _inputNumber / 2; checkFactor += 1)
	{
		if (_inputNumber % checkFactor == 0)
			returnList.push_back(checkFactor);
	}

	return returnList;
}

std::vector<std::string> TemplateProject::ReadTextFile(const std::string _fileName)
{
	std::vector<std::string> returnStrings;
	std::fstream inputFile(_fileName);
	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			returnStrings.push_back(line);
		}
	}
	else
	{
		std::cout << "Unable to read this file" << std::endl;
	}

	return returnStrings;
}
