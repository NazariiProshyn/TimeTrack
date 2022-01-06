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
	void parsInformation(const std::string& info);
	int checkName();
	int checkDay();
	int checkHours();
	bool checkFormatDate();

	bool validateHours();
	const std::string& getName() const { return values[name]; }
	const int getHour() { return std::stoi(values[hours]); }
	const std::string& getYear();
	const std::string& getMonth();
private:
	bool checkSign(char sign);
	bool validateMonth();
	bool validateDay();

	std::string parsingString = "";
	std::string infoString    = "";

	std::vector<std::string> parsDate;
	std::vector<std::string> columns;
	std::vector<std::string> values;

	int name  = -1;
	int day   = -1;
	int hours = -1;
};

