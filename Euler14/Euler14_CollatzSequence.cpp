#include "Euler14_CollatzSequence.h"
#include <iostream>

Euler14_CollatzSequence::Euler14_CollatzSequence()
{
}

Euler14_CollatzSequence::~Euler14_CollatzSequence()
{
}

std::string Euler14_CollatzSequence::Name()
{
	return "Euler 14 Collatz Sequence";
}

void Euler14_CollatzSequence::Run()
{
	int longestChain = 0;
	long long longestChainNumber = 0;
	for (long long startingNumber = 1; startingNumber < 1000000; startingNumber++)
	{	
		long long value = startingNumber;
		int chain = 0;
		while (value != 1)
		{
			if (value % 2 == 0)
				value /= 2;
			else
				value = 3 * value + 1;		
			chain++;
		}

		if (chain > longestChain)
		{
			longestChain = chain;
			longestChainNumber = startingNumber;
			printf("\n Longest Chain so far: %d from %lld", longestChain, startingNumber);
		}
	}

	printf("\nLongest Chain is : %d from %lld", longestChain, longestChainNumber);

}
