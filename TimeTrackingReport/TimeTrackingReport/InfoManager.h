#pragma once
#include <string>
#include <fstream>
#include "Employee.h"
#include "Parser.h"

class InfoManager final
{
public:
	InfoManager() = default;
	~InfoManager() = default;
	void SetFileName();
	void ReadInformation();
private:
	void LeadToTheStandard();
	void checkFileRequirements();

	std::string readString = "";
	std::string fileName = "";
	std::ifstream fin;

	std::vector<Employee> employees;
	Parser parser;
};

