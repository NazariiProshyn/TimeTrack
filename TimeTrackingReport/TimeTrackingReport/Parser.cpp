#include "Parser.h"
#include <algorithm>
#include <iostream>
#include <map>

namespace NSParserProperties
{
	const std::vector<char> signs =
	{
		',',
		';'
	};
	const std::string name = "name";
	const std::string date  = "date";
	const std::string hour = "loggedhours";
	const size_t minHours = 0;
	const size_t maxHours = 24;
}

namespace NSMontsConstants
{

	const char dateSign = '-';
	const size_t year = 0;
	const size_t month = 1;
	const size_t day = 2;
	const size_t dateSize = 3;
	const size_t minNumOfMonthAndDay = 1;
	const size_t maxNumOfMonth = 12;
	const std::vector<int> daysInMonth =
	{
		0,
		31,
		28,
		31,
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31
	};
	std::map<std::string, std::string> monthList =
	{
		{"1","January"},
		{"2","February"},
		{"3","March"},
		{"4","April"},
		{"5","May"},
		{"6","June"},
		{"7","July"},
		{"8","August"},
		{"9","September"},
		{"10","October"},
		{"11","November"},
		{"12","December"}
	};
}

void Parser::SetColumnsNames(const std::string& info)
{
	infoString = info;

	std::transform(infoString.begin(), infoString.end(), infoString.begin(), tolower);
	infoString.erase(
		std::remove(infoString.begin(), infoString.end(), ' '), infoString.end());
	infoString += ';';
	
	for (size_t i = 0; i < infoString.size(); ++i)
	{
		if (checkSign(infoString[i]))
		{
			columns.push_back(parsingString);
			parsingString.clear();
		}
		else
		{
			parsingString += infoString[i];
		}
	}


	//std::cout << '\n';
	//for (size_t i = 0; i < columns.size(); ++i)
	//{
	//	std::cout << columns[i];
	//}
	//std::cout << '\n';
}

void Parser::parsInformation(const std::string& info)
{
	infoString = info + ';';
	values.clear();
	for (size_t i = 0; i < infoString.size(); ++i)
	{
		if (checkSign(infoString[i]))
		{
			values.push_back(parsingString);
			parsingString.clear();
		}
		else
		{
			parsingString += infoString[i];
		}
	}
	//std::cout << values[name] << ' ';
	//std::cout << values[day] << ' ';
	//std::cout << values[hours] << ' ';
	//std::cout << '\n';
/*
	for (size_t i = 0; i < columns.size(); ++i)
	{
		std::cout << values[i] << ' ';
	}
	std::cout <<'\n';*/
}

int Parser::checkName()
{
	for (size_t i = 0; i < columns.size(); ++i)
	{
		if (columns[i] == NSParserProperties::name)
		{
			name = i;
		}
	}
	return name;
}

int Parser::checkDay()
{
	for (size_t i = 0; i < columns.size(); ++i)
	{
		if (columns[i] == NSParserProperties::date)
		{
			day = i;
		}
	}
	return day;
}

int Parser::checkHours()
{
	for (size_t i = 0; i < columns.size(); ++i)
	{
		if (columns[i] == NSParserProperties::hour)
		{
			hours = i;
		}
	}
	return hours;
}

bool Parser::checkFormatDate()
{
	parsDate.clear();
	values[day] += NSMontsConstants::dateSign;
	for (size_t i = 0; i < values[day].size(); ++i)
	{
		if (values[day][i] == NSMontsConstants::dateSign)
		{
			parsDate.push_back(parsingString);
			parsingString.clear();
		}
		else
		{
			parsingString += values[day][i];
		}
	}

	if (parsDate.size() != NSMontsConstants::dateSize)
	{
		return false;
	}
	
	return (validateMonth() && validateDay());
}

bool Parser::validateHours()
{
	return (std::stoi(values[hours]) >= 
		NSParserProperties::minHours) &&
		(std::stoi(values[hours]) <=
		NSParserProperties::maxHours);
}

const std::string& Parser::getYear()
{
	return values[NSMontsConstants::year];
}

const std::string& Parser::getMonth()
{
	return NSMontsConstants::monthList.find(parsDate[1])->second;
}

bool Parser::checkSign(char sign)
{
	for (size_t i = 0; i < NSParserProperties::signs.size(); ++i)
	{
		if (sign == NSParserProperties::signs[i])
		{
			return true;
		}
	}
	return false;
}

bool Parser::validateMonth()
{
	return (std::stoi(parsDate[NSMontsConstants::month]) >=
		NSMontsConstants::minNumOfMonthAndDay) &&
		(std::stoi(parsDate[NSMontsConstants::month]) <=
		NSMontsConstants::maxNumOfMonth);
}

bool Parser::validateDay()
{
	return (std::stoi(parsDate[NSMontsConstants::day]) >=
		NSMontsConstants::minNumOfMonthAndDay) &&
		(std::stoi(parsDate[NSMontsConstants::day]) <=
		NSMontsConstants::daysInMonth[std::stoi(parsDate[NSMontsConstants::month])]);
}