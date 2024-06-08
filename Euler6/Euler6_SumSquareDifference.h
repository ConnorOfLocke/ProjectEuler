#pragma once
#include "../TemplateProject.h"

class Euler6_SumSquareDifference : TemplateProject
{
public:
	//Constructors
	Euler6_SumSquareDifference();
	~Euler6_SumSquareDifference();

	//Overrides
	std::string Name();
	void Run();
};