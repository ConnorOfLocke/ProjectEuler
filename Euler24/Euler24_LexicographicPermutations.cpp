#include "Euler24_LexicographicPermutations.h"
#include <algorithm>
#include <iostream>

Euler24_LexicographicPermutations::Euler24_LexicographicPermutations()
{
}

Euler24_LexicographicPermutations::~Euler24_LexicographicPermutations()
{
}

std::string Euler24_LexicographicPermutations::Name()
{
	return "Euler 24 Lexicographic Permutations";
}

void Euler24_LexicographicPermutations::Run()
{
	//Find the millionth lexicographic permutation of the digits 0,1,2,3,4,5,6,7,8,9
	//Finding all of them would be 10!

	// 0!value is : 1
	// 1!value is : 1
	// 2!value is : 2
	// 3!value is : 6
	// 4!value is : 24
	// 5!value is : 120
	// 6!value is : 720
	// 7!value is : 5040
	// 8!value is : 40320
	// 9!value is : 362880
	// 10!value is : 3628800

	const int factorialSize = 10;
	int factorials[factorialSize] = { 1,1,2,6,24,120,720,5040, 40320, 362880 };// , 3628800 };
	std::vector<char> availableChars{ '0','1','2','3','4','5','6','7','8','9'};

	// starting with 0 - (0! + 9!)
	// starting with 01 - (0* 0!+0*1! +( 8!))
	// starting with 1 - (1 * 9!)
	// starting with 2 - (2 * 9!)

	int targetIndex = 999999;

	int returnIndex[factorialSize] = {0,0,0,0,0,0,0,0,0};
	while (targetIndex > 0)
	{
		for (int i = factorialSize - 1; i >= 0; i--)
		{
			if (targetIndex >= factorials[i])
			{
				returnIndex[i] += 1;
				targetIndex -= factorials[i];
				break;
			}
		}
	}

	//Go backwards through our returnIndexs
	printf("\n");
	std::vector<char> returnChars;
	for (int i = factorialSize - 1; i >= 0; i--)
	{
		returnChars.push_back(availableChars[returnIndex[i]]);
		availableChars.erase(availableChars.begin() + returnIndex[i]);

		printf("%c", returnChars[returnChars.size() - 1]);
	}

}
