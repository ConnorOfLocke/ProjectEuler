#pragma once

#include <string>
#include <vector>
#include <string>

class TemplateProject
{
public:
	virtual std::string Name() = 0;
	virtual void Run() = 0;

protected:
	int GetInputValue();
	std::vector<long> GeneratePrimes(const long _upperBound);
	std::string AddHugeNumbers(const std::vector<std::string> _inputNumbers);
	std::string AddHugeNumbers(const std::string input1, const std::string input2);
	std::vector<int> GetFactors(const int _inputNumber);
	std::vector<std::string> ReadTextFile(const std::string _fileName);

};