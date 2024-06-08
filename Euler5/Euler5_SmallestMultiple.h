#pragma once
#include "../TemplateProject.h"

class Euler5_SmallestMultiple : TemplateProject
{
public:
	//Constructors
	Euler5_SmallestMultiple();
	~Euler5_SmallestMultiple();

	//Overrides
	std::string Name();
	void Run();
};