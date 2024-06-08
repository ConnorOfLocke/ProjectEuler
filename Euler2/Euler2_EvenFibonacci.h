#pragma once
#include "../TemplateProject.h"

class Euler2_EvenFibonacci : TemplateProject
{
public:
	//Constructors
	Euler2_EvenFibonacci();
	~Euler2_EvenFibonacci();

	//Overrides
	std::string Name();
	void Run();
};