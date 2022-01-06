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
	void WriteInformation();
private:
	void LeadToTheStandard();
	void CheckFileRequirements();
	void ManageEmployees();

	std::string readString = "";
	std::string fileName   = "";
	std::string resultFileName = "result";
	std::ifstream fin;
	std::ofstream fout;

	std::vector<Employee> employees;
	Parser parser;
};

