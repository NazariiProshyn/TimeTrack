#pragma once
/**
 * @file      Parser.h
 *
 * @brief     Structure to parse and check information
 *
 *
 */
#include <map>
#include <string>
#include <vector>

class Parser final
{
public:
	Parser()  = default;
	~Parser() = default;

	/**
	 * @brief		Parse a string into columns
	 *
	 * @param info	string table header
	 *
	*/
	void SetColumnsNames(const std::string& info);

	/**
	 * @brief		Parse a string into columns
	 *
	 * @param info	string with information
	 *              about time tracking
	 *
	*/
	void ParsInformation(const std::string& info);

	/**
	 * @brief	Checks availability column "Name" 
	 *
	 * @return  Num of column "Name".
	*/
	int  CheckName();

	/**
	 * @brief	Checks availability column "Day"
	 *
	 * @return  Num of column "Day".
	*/
	int  CheckDay();

	/**
	 * @brief	Checks availability column "Hours"
	 *
	 * @return  Num of column "Hours".
	*/
	int  CheckHours();

	/**
	 * @brief	Checks format of date
	 *			(YYYY-MM-DD)
	 *
	 * @return Date format status.
	*/
	bool CheckFormatDate();

	/**
	 * @brief	Checks format of Hours
	 *
	 * @return Hours format status.
	*/
	bool ValidateHours();

	/**
	 * @brief	Returns value of column "Name".
	 *
	 * @return  Value of column "Name".
	*/
	const std::string& GetName() const { return values[name]; }

	/**
	 * @brief	Returns value of column "Logged Hour".
	 *
	 * @return  Value of column "Logged Hour".
	*/
	const int getHour() const { return std::stoi(values[hours]); }

	/**
	 * @brief	Returns value of column "Year".
	 *
	 * @return  Value of column "Year".
	*/
	const std::string& GetYear()  const;

	/**
	 * @brief	Returns value of column "Month".
	 *
	 * @return  Value of column "Month".
	*/
	const std::string& GetMonth() const;
private:

	/**
	 * @brief		Checks each string character 
	 *				for separable.
	 * 
	 * @param sign  character for checking
	 * 
	 * @return		Character type information
	 *				(true if separate).
	*/
	bool CheckSign(char sign) const;

	/**
	 * @brief	Checks month information for validity
	 *
	 * @return Month information validity.
	*/
	bool ValidateMonth() const;

	/**
	 * @brief	Checks day information for validity
	 *
	 * @return  Day information validity.
	*/
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
