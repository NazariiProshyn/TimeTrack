#pragma once
#include <string>
#include <fstream>
#include "Employee.h"
#include "Parser.h"
#include "Logger.h"

namespace NSLogger {
	static const std::string path      = "Log.txt";
	static const std::string openFile  = "File open: ";
	static const std::string readInfo  = "Read information";
	static const std::string writeInfo = "Write information";
	static const std::string closeFile = "File close: ";
	static const std::string canRead   = "Can't read:";
}

class InfoManager final
{
public:
	InfoManager() : logger(NSLogger::path) {};
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
	Logger logger;
};
