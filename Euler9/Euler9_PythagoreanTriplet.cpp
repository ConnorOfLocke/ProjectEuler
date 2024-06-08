#include "Euler9_PythagoreanTriplet.h"
#include <iostream>

Euler9_PythagoreanTriplet::Euler9_PythagoreanTriplet()
{
}

Euler9_PythagoreanTriplet::~Euler9_PythagoreanTriplet()
{
}

std::string Euler9_PythagoreanTriplet::Name()
{
	return "Euler9 Pythagorean Triplet";
}

void Euler9_PythagoreanTriplet::Run()
{
	int targetNumber = 1000;

	// a < b < c
	// find a^2 + b^2 + c^2 = 100000
	// 
	// therefore a + b + c = 1000
	// 
	// like 3^2 + 4^2 = 5^2

	for (int c = 999; c > 0; c--)
	{
		for (int b = 999; b > 0; b--)
		{						
			for (int a = 999; a > 0; a--)
			{
				if (a + b + c == targetNumber && (a * a + b * b == c * c))
				{					
					std::cout << "Found them: " << a << " " << b << " " << c << std::endl;
					std::cout << "Product of which is " << a * b * c << std::endl;
					return;					
				}
			}
		}
	}
	

}
