#include "Euler4_LargestPalindrome.h"
#include <iostream>

Euler4_LargestPalindrome::Euler4_LargestPalindrome()
{
}

Euler4_LargestPalindrome::~Euler4_LargestPalindrome()
{
}

std::string Euler4_LargestPalindrome::Name()
{
	return "Euler4 Largest Palindrome Product";
}

void Euler4_LargestPalindrome::Run()
{
	int highestBound = 999;
	//This needs a look over. It gives a correct result but not in higher numbers

	long long highestPalindrome = 0;
	int factor1 = 0, factor2 = 0;
	//Find the largest palindrome made from the product of two 3 digit numbers.
	int bottomLimit = highestBound / 2;
	for (int check2 = highestBound; check2 > bottomLimit; check2--)
	{
		for (int check1 = highestBound; check1 > bottomLimit; check1--)
		{
			if (CheckPalindromeNumber(check1 * check2))
			{
				std::cout << check1 << " * " << check2 << "=" << (check1 * check2) << std::endl;
				
				if (highestPalindrome < check1 * check2)
				{
					highestPalindrome = check1 * check2;
					factor1 = check1;
					factor2 = check2;
				}

				bottomLimit = (check1 < check2) ? check1 : check2;
				std::cout << "Bottom limit is now: " << bottomLimit << std::endl;
				break;
			}
		}
	}

	std::cout << std::endl << "Highest Palindrome is " << std::endl
			<< factor1 << " * " << factor2 << " = " << highestPalindrome << std::endl;
}

bool Euler4_LargestPalindrome::CheckPalindromeNumber(long long _input)
{
	std::string checkString = std::to_string(_input);
	int size = (int)checkString.size();
	for (int i = 0; i < size / 2; i++)
	{
		if (checkString[i] != checkString[(size - 1) - i])
		{
			return false;
		}
	}

	return true;
}
