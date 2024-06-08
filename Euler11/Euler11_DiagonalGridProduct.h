#pragma once
#include "../TemplateProject.h"

class Euler11_DiagonalGridProduct : TemplateProject
{
public:
	//Constructors
	Euler11_DiagonalGridProduct();
	~Euler11_DiagonalGridProduct();

	//Overrides
	std::string Name();
	void Run();

private:
	int XYtoIndex(int _x, int _y, int _rowWidth);
};