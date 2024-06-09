#include "Euler28_NumberSpiralDiagonals.h"
#include <iostream>
#include <map>

Euler28_NumberSpiralDiagonals::Euler28_NumberSpiralDiagonals()
{
}

Euler28_NumberSpiralDiagonals::~Euler28_NumberSpiralDiagonals()
{
}

std::string Euler28_NumberSpiralDiagonals::Name()
{
	return "Euler 28 Number Spiral Diagonals";
}

void Euler28_NumberSpiralDiagonals::Run()
{
	//determine the sum of the diagonals in 1001x1001 number spiral

	//top right is always where the last number is
	//1 - 9 - 25	
	
	//really we're just calculating the top right corner

	int size = 1001;

	int maxLayer = (size - 1) / 2;
	unsigned long sum = 1;
	for (unsigned long layer = 1; layer <= maxLayer; layer++)
	{
		unsigned long topRight = (2 * layer + 1) * (2 * layer + 1);
		//top right
		sum += topRight;
		//top left
		sum += topRight - (layer * 2);
		//bottom left
		sum += topRight - (layer * 4);
		//bottom right
		sum += topRight - (layer * 6);
	}

	std::cout << "\nWow, our spiral sum number is: " << sum;
}
