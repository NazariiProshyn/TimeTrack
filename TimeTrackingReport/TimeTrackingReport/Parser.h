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
	void ParsInformation(const std::string& info);

	int  CheckName();
	int  CheckDay();
	int  CheckHours();
	bool CheckFormatDate();
	bool ValidateHours();

	const std::string& GetName() const { return values[name]; }
	const int getHour() const { return std::stoi(values[hours]); }
	const std::string& GetYear()  const;
	const std::string& GetMonth() const;
private:
	bool CheckSign(char sign) const;
	bool ValidateMonth() const;
	bool ValidateDay() const;

	std::string parsingString = "";
	std::string infoString    = "";

	std::vector<std::string> parsDate;
	std::vector<std::string> columns;
	std::vector<std::string> values;

	int name  = -1;
	int day   = -1;
	int hours = -1;
};

