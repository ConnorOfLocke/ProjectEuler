#pragma once
#include "../TemplateProject.h"

class NameValue
{
public:
	NameValue(std::string _name, int _value);

	//Returns -1, 0, 1 alphabetically
	int Compare(NameValue& val);

	std::string name;
	int value;
};

class Euler22_NamesScores : TemplateProject
{
public:
	//Constructors
	Euler22_NamesScores();
	~Euler22_NamesScores();

	//Overrides
	std::string Name();
	void Run();

private:
	int StringToValue(const std::string _input);
	void QuickSort(std::vector<NameValue>& _names, int _startIndex, int _endIndex);	

	std::string delimiter = ",";
};

