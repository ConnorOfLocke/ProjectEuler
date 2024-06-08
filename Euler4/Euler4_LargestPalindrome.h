#pragma once
#include "../TemplateProject.h"

class Euler4_LargestPalindrome : TemplateProject
{
public:
	//Constructors
	Euler4_LargestPalindrome();
	~Euler4_LargestPalindrome();

	//Overrides
	std::string Name();
	void Run();
private:
	bool CheckPalindromeNumber(long long _input);
};