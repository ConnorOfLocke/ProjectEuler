#include "Euler1_3_5_Multiples.h"
#include <iostream>

Euler1_3_5_Multiples::Euler1_3_5_Multiples()
{}

Euler1_3_5_Multiples::~Euler1_3_5_Multiples()
{}

std::string Euler1_3_5_Multiples::Name() 
{
	return "Euler1 3 and 5 Multiples";
}

void Euler1_3_5_Multiples::Run()
{
	std::string input;

	std::cout << "Set a number to find the sum of all the multiples of 3 or 5 below: " << std::endl;
	std::cin >> input;

	int inputNumber = 0;
	try {
		inputNumber = std::stoi(input);
	}
	catch (...)
	{
		std::cout << "Invalid input : " << input;
		return;
	}

	int result = 0;

	for (int count = 3; count < inputNumber; count++)
	{
		if (count % 3 == 0 || count % 5 == 0)
		{
			std::cout << " " << count;
			result += count;
		}
	}

	std::cout << std::endl << "Result number from " << inputNumber << " is " << result << std::endl;
}
