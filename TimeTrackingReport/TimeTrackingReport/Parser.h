#pragma once
#include <map>
#include <string>
#include <vector>

class Parser final
{
public:
	Parser()  = default;
	~Parser() = default;
	void SetColumnsNames(const std::string& info);
	int checkName();
	int checkDay();
	int checkHours();
private:
	bool checkSign(char sign);

	std::string parsingString = "";
	std::string infoString    = "";

	std::vector<std::string> columns;
	std::vector<std::string> values;

	int name  = -1;
	int day   = -1;
	int hours = -1;
};

