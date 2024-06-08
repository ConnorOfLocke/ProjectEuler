#include "Euler7_FindAPrime.h"
#include <iostream>
#include <cmath>
#include <vector>

Euler7_FindAPrime::Euler7_FindAPrime()
{
	
}

Euler7_FindAPrime::~Euler7_FindAPrime()
{
}

std::string Euler7_FindAPrime::Name()
{
	return "Euler 7 Find a Prime";
}

void Euler7_FindAPrime::Run()
{
	std::cout << "Enter a placement for a prime: " << std::endl;
	int inputNumber = GetInputValue();

	//We can get the bounds to get vaguely in the ballpark for the nth prime
	//https://math.stackexchange.com/questions/1270814/bounds-for-n-th-prime
	//n ( ln(n)+ln(ln(n)) ) > pn > n(ln(n)+ln(ln(n))−1)
	
	long higherBound = (long)ceil(inputNumber * (log (inputNumber) + log(log(inputNumber))));
	long lowerBound = (long)floor(inputNumber * (log(inputNumber) + log(log(inputNumber)) - 1 ));

	std::cout << "Your prime is between " << lowerBound << " and " << higherBound << std::endl;

	std::vector<long> primeList = GeneratePrimes(higherBound);

	//assuming the upperbound is correct, we should just be able to get the index
	std::cout << "Your prime at index " << inputNumber << ": " << primeList[inputNumber - 1];	
}
