#include "Euler27_QuadraticPrimes.h"
#include <iostream>
#include <map>

Euler27_QuadraticPrimes::Euler27_QuadraticPrimes()
{
}

Euler27_QuadraticPrimes::~Euler27_QuadraticPrimes()
{
}

std::string Euler27_QuadraticPrimes::Name()
{
	return "Euler 27 Quadratic Primes";
}

void Euler27_QuadraticPrimes::Run()
{
	// n^2 + n + 41 
	// 0 through 39 produces prime numbers,
	// n=40 and n=41, the results are both divisible by 41

	//n^2 - 79n + 1601
	// 0 through 79 produces prime numbers
	// the product of the equations coeffcients -79 and 1601 is -126479

	//f(n) n^2 + an + b where abs(a) < 1000 and abs(b) < 1000
	//
	//find a and b where the equation produces the maximum number of consecutive primes starting with n = 0

	int maxValue = 1000;
	int highestPrimeCount = 0;
	int best_a = 1, best_b = 1;

	enum State
	{
		NotAnalysed,
		Prime,
		NotAPrime
	};

	//so we don't gave to recheck previously calculated primes
	std::map<int, State> primesSoFar;

	for (int a = -maxValue; a < maxValue; a++)
	{
		for (int b = -maxValue; b < maxValue; b++)
		{
			int n = 0; 
			bool foundNotAPrime = false;
			while (!foundNotAPrime)
			{
				int value = n * n + a * n + b;

				if (primesSoFar[value] == State::NotAnalysed)
				{
					primesSoFar[value] = CheckIsPrime(value) ? State::Prime : State::NotAPrime;
				}

				if (value > 0 && primesSoFar[value] == State::Prime)
				{
					n++;					
				}
				else
				{
					foundNotAPrime = true;
				}
			}

			if (n > highestPrimeCount)
			{				
				highestPrimeCount = n;
				best_a = a;
				best_b = b;
				printf("\nHighest coefficients so far: %d Primes - n^2 + (%d)n + (%d)", n, a, b);
			}
		}
	}

	printf("\nWinner is: %d Primes - n^2 + (%d)n + (%d)", highestPrimeCount, best_a, best_b);
	printf("\nCoefficients together are (%d)", best_a * best_b);


}
