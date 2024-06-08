#include "Euler10_SumationOfPrimes.h"
#include <iostream>

Euler10_SumationOfPrimes::Euler10_SumationOfPrimes()
{
}

Euler10_SumationOfPrimes::~Euler10_SumationOfPrimes()
{
}

std::string Euler10_SumationOfPrimes::Name()
{
	return "Euler 10 Sumation of Primes";
}

void Euler10_SumationOfPrimes::Run()
{
	long upperBound = 2000000;

	std::cout << "Finding all the primes below: " << upperBound << std::endl;
	std::vector<long> primeList = GeneratePrimes(upperBound);
	int primeCount = (int)primeList.size();
	std::cout << "Primes found: " << primeCount << " ending with " << primeList[primeCount -1] << std::endl;

	///Should be 148933

	long long sum = 0;
	for (int i = 0; i < primeCount; i++)
	{
		sum += primeList[i];
	}

	std::cout << "The sum of all primes below " << upperBound << " is " << sum << std::endl;
}
