#include "Euler12_TriangleNumberFactors.h"
#pragma once

Euler12_TriangleNumberFactors::Euler12_TriangleNumberFactors()
{
}

Euler12_TriangleNumberFactors::~Euler12_TriangleNumberFactors()
{
}

std::string Euler12_TriangleNumberFactors::Name()
{
	return "Euler 12 Trangle Number Factors";

}

void Euler12_TriangleNumberFactors::Run()
{
	int target_divisibles = 500;
	printf("Starting our search for a triangle number with > %d divisors", target_divisibles);
	
	bool found = false;
	int count = 1;
	while (!found)
	{
		//from n(n+1)/2
		long long tri_number = (count * (count + 1)) / 2;
		printf("Checking %d: ~~~ triNum - %lld ", count, tri_number);		
		
		//Find all the divisors
		int divisorCount = 0;
		long long tri_num_sqroot = (long long)sqrtl((long double)tri_number);
		for (long long i = 1; i <= tri_num_sqroot + 1; i++)
		{
			if (tri_number % i == 0)
			{
				long long check  = tri_number / i;
				if ((check == i))
				{
					divisorCount += 1;
				}
				else
				{
					divisorCount += 2;
				}
			}
		}

		printf("~~~ %d divisors\n", divisorCount);

		found = divisorCount >= target_divisibles;

		if (found)
		{
			printf("%d: Found the number! %lld with %d divisors\n", count, tri_number, divisorCount);
		}
		count++;		
	}
}
