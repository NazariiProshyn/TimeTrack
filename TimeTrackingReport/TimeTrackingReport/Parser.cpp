#include "Parser.h"
#include <algorithm>
#include <iostream>

namespace NSParserProperties
{
	const std::vector<char> signs =
	{
		',',
		';'
	};
	const std::string name = "name";
	const std::string day  = "date";
	const std::string hour = "loggedhours";
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
		if (columns[i] == NSParserProperties::day)
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
