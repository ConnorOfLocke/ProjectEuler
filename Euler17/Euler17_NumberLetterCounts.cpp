#include "Euler17_NumberLetterCounts.h"
#include <iostream>

Euler17_NumberLetterCounts::Euler17_NumberLetterCounts()
{
}

Euler17_NumberLetterCounts::~Euler17_NumberLetterCounts()
{
}

std::string Euler17_NumberLetterCounts::Name()
{
	return "Euler 17 Number Letter Counts";
}

std::string Euler17_NumberLetterCounts::Tens(int input)
{
	if (input < 10)
	{
		return digits[input];
	}
	else if (input < 20)
	{
		return teens[input % 10];
	}

	int tensIndex = (input / 10) % 10;
	return tens[tensIndex] + ((input % 10 == 0) ? "" : digits[input % 10]);
}

std::string Euler17_NumberLetterCounts::Hundreds(int input)
{
	int hundredsIndex = (input / 100) % 100;	

	if (input % 100 == 0)
	{
		return digits[hundredsIndex] + hundred;
	}

	return digits[hundredsIndex] + hundred + _and + Tens(input % 100);
}

std::string Euler17_NumberLetterCounts::Thousands(int input)
{
	int hundredsIndex = (input / 1000) % 1000;	

	if (input % 1000 == 0)
	{
		return digits[hundredsIndex] + thousand;
	}

	return digits[hundredsIndex] + thousand + _and + Hundreds(input % 1000);

}

void Euler17_NumberLetterCounts::Run()
{
	//Count the letters in the number sequence from 1 to 1000
	
	// 342 = "three hundred and forty-two" - has 23 letters 
	// 115 = "one hundred and fifteen" - has 20 letters

	int target = 1000;	

	printf("Starting to count to %d \n", target);
	long letterCount = 0;
	for (int i = 1; i <= target; i++)
	{
		std::string resultString = "";		
		if  (i < 100)
		{			
			resultString = Tens(i);
		}
		else if (i < 1000)
		{
			resultString = Hundreds(i);
		}
		else
		{
			resultString = Thousands(i);
		}

		std::cout << resultString << ", " << std::endl;
		letterCount += (int)resultString.size();
	}

	std::cout << "Final letter count is " << letterCount << std::endl;



}


