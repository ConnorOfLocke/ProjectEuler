#include "Euler22_NamesScores.h"
#include <iostream>
#include <string>

Euler22_NamesScores::Euler22_NamesScores()
{
}

Euler22_NamesScores::~Euler22_NamesScores()
{
}

std::string Euler22_NamesScores::Name()
{
	return "Euler 22 Names Scores";
}

void Euler22_NamesScores::Run() 
{
	std::string fileInputString = ReadTextFile("0022_names.txt")[0];
	
	std::vector<NameValue> names;

	//Parse all the names to thier values
	std::size_t pos = 0;
	std::string extractedName;
	while ((pos = fileInputString.find(delimiter)) != std::string::npos)
	{
		extractedName = fileInputString.substr(0, pos);

		//remove the quotes
		extractedName.erase(extractedName.begin());
		extractedName.erase(extractedName.end() - 1);
		
		NameValue newName(extractedName, StringToValue(extractedName));

		names.push_back(newName);

		//remove the name from the string
		fileInputString.erase(0, pos + delimiter.length());
	}

	//Take out the final name
	fileInputString.erase(fileInputString.begin());
	fileInputString.erase(fileInputString.end() - 1);
	NameValue newName(fileInputString, StringToValue(fileInputString));
	names.push_back(newName);
	
	/*
	std::vector< NameValue> testNames;
	testNames.push_back(NameValue("WILLIAM", StringToValue("WILLIAM")));
	testNames.push_back(NameValue("VICTOR", StringToValue("VICTOR")));
	testNames.push_back(NameValue("URD", StringToValue("URD")));
	testNames.push_back(NameValue("TREVOR", StringToValue("TREVOR")));
	testNames.push_back(NameValue("SEEEL", StringToValue("SEEEL")));
	testNames.push_back(NameValue("ROGATHON", StringToValue("ROGATHON")));
	testNames.push_back(NameValue("QUERB", StringToValue("QUERB")));
	testNames.push_back(NameValue("PEEEN", StringToValue("PEEEN")));
	testNames.push_back(NameValue("OLIVER", StringToValue("OLIVER")));
	testNames.push_back(NameValue("NATILDA", StringToValue("NATILDA")));
	testNames.push_back(NameValue("HAMS", StringToValue("HAMS")));
	testNames.push_back(NameValue("HAMS", StringToValue("HAMS")));
	testNames.push_back(NameValue("HAMS", StringToValue("HAMS")));
	testNames.push_back(NameValue("GEORGE", StringToValue("GEORGE")));
	testNames.push_back(NameValue("FRED", StringToValue("FRED")));
	testNames.push_back(NameValue("EGBERT", StringToValue("EGBERT")));
	testNames.push_back(NameValue("DEREK", StringToValue("DEREK")));
	testNames.push_back(NameValue("CRAMDOR", StringToValue("CRAMDOR")));
	testNames.push_back(NameValue("BUFFANY", StringToValue("BUFFANY")));
	testNames.push_back(NameValue("AARON", StringToValue("AARON")));
	testNames.push_back(NameValue("ZEBRA",		StringToValue("ZEBRA")));
	testNames.push_back(NameValue("YENNEFER",	StringToValue("YENNEFER")));
	testNames.push_back(NameValue("XAM",			StringToValue("XAM")));
	testNames.push_back(NameValue("MATILLDA",	StringToValue("MATILLDA")));
	testNames.push_back(NameValue("LEMON",		StringToValue("LEMON")));
	testNames.push_back(NameValue("KRONK",		StringToValue("KRONK")));
	testNames.push_back(NameValue("JIMOTHY",		StringToValue("JIMOTHY")));
	testNames.push_back(NameValue("INDIGO",		StringToValue("INDIGO")));
	testNames.push_back(NameValue("HAMS",		StringToValue("HAMS")));

	QuickSort(testNames, 0, (int)testNames.size() - 1);

	std::cout << std::endl << "Final Sorted names: ";
	for (int i = 0; i < testNames.size(); i++)
	{
		std::cout << testNames[i].name << " ";
	}
	*/	

	int nameSize = (int)names.size();
	QuickSort(names, 0, nameSize - 1);
	std::cout << std::endl << std::endl << "Sorted names alphabetically :";

	//Now times the name value by its place and ad it all together
	long long total = 0; 
	for (int i = 0; i < nameSize; i++)
	{
		int value = names[i].value * (i + 1);		
		std::cout << " " << names[i].name << "-" << (i + 1);
		total += names[i].value * (i + 1);
	}	
	printf("\n\nGrand total iiiiisss: %lld", total);	
}

int Euler22_NamesScores::StringToValue(const std::string _input)
{
	int value = 0;
	for (auto iter = _input.begin(); iter != _input.end(); iter++)
	{		
		//Makes A = 1 rather than 'A' = 65
		value += ((int)*iter) - 64;
	}

	return value;
}

void Euler22_NamesScores::QuickSort(std::vector<NameValue>& _names, int _startIndex, int _endIndex)
{	
	/*
	std::cout << std::endl << "Pre : ";
	for (int i = _startIndex; i <= _endIndex; i++)
	{
		std::cout << _names[i].name << " ";
	}*/

	//initially swap our pivot
	int pivot = (_startIndex + _endIndex) / 2;
	NameValue tempPivot = _names[pivot];
	_names[pivot] = _names[_endIndex];
	_names[_endIndex] = tempPivot;

	pivot = _endIndex;
	int leftBound = _startIndex;
	int rightBound = pivot - 1;
	//split out to higher or lower than our pivot
	bool movingRight = true;
	bool foundPlace = false;
	while (!foundPlace)
	{
		//move leftbound right until we've found something bigger than the pivot or we've hit the pivot
		if (movingRight)
		{			
			if (_names[leftBound].Compare(_names[pivot]) >= 0)
				movingRight = false;
			else			
				leftBound++;			
		}
		else
		{			
			//move right until we've hit past the left or found something smaller than the pivot
			if (rightBound < leftBound)
			{
				NameValue temp = _names[leftBound];
				_names[leftBound] = _names[pivot];
				_names[pivot] = temp;

				foundPlace = true;
			}
			//Swap the left and right bounds and continue moving right
			else if (_names[rightBound].Compare(_names[pivot]) < 0)
			{
				NameValue temp = _names[leftBound];
				_names[leftBound] = _names[rightBound];
				_names[rightBound] = temp;
				movingRight = true;
			}
			else
			{
				rightBound--;
			}
		}
	}

	/*
	std::cout << std::endl << "Post: ";
	for (int i = _startIndex; i <= _endIndex; i++)
	{
		std::cout << _names[i].name << " ";
	}*/

	//Recurse through the left and right sub arrays
	if (_startIndex < leftBound)
		QuickSort(_names, _startIndex, leftBound - 1);

	if (leftBound + 1 < _endIndex)
		QuickSort(_names, leftBound + 1, _endIndex);
}

NameValue::NameValue(std::string _name, int _value)
{
	name = _name;
	value = _value;
}

int NameValue::Compare(NameValue& _val)
{
	size_t strSize = _val.name.size() < name.size() ? _val.name.size() : name.size();
	for (int index = 0; index < strSize; index++)
	{
		if (name[index] > _val.name[index])
		{
			//goes after
			return 1;
		}
		else if (name[index] < _val.name[index])
		{
			//goes before
			return -1;
		}
		else if (index == strSize - 1)
		{
			//equal in every way
			if (_val.name.size() == name.size())
				return 0;
			//the shorter would be alphabetically first
			return (name.size() == strSize) ? -1 : 1;
		}
	}

	return 0;
}
