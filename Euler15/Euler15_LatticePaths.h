#pragma once
#include "../TemplateProject.h"

class Euler15_LatticePaths : TemplateProject
{
public:
	//Constructors
	Euler15_LatticePaths();
	~Euler15_LatticePaths();

	//Overrides
	std::string Name();
	void Run();

private:

};