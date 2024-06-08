#pragma once
#include "../TemplateProject.h"

class Euler17_NumberLetterCounts : TemplateProject
{
public:
	//Constructors
	Euler17_NumberLetterCounts();
	~Euler17_NumberLetterCounts();

	//Overrides
	std::string Name();
	void Run();

private:
	std::string Tens(int input);
	std::string Hundreds(int input);
	std::string Thousands(int input);

	std::string _and = "and";
	std::string hundred = "hundred";
	std::string thousand = "thousand";
	std::vector<std::string> digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	std::vector<std::string> teens = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	std::vector<std::string> tens = { "nonety", "onety", "twenty", "thirty","forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
};