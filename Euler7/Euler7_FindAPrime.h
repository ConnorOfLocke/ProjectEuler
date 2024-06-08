#pragma once
#include "../TemplateProject.h"
#include <vector>

class Euler7_FindAPrime : TemplateProject
{
public:
	//Constructors
	Euler7_FindAPrime();
	~Euler7_FindAPrime();

	//Overrides
	std::string Name();
	void Run();
};