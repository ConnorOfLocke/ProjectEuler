#pragma once
#include "../TemplateProject.h"

class Euler26_ReciprocalCycles : TemplateProject
{
public:
	//Constructors
	Euler26_ReciprocalCycles();
	~Euler26_ReciprocalCycles();

	//Overrides
	std::string Name();
	void Run();

private:
	bool FindRepeatingPattern(std::string const& input, std::string& output);

};