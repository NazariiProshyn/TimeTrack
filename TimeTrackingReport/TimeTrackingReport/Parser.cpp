#include "Parser.h"
#include <algorithm>
#include <iostream>
void Parser::SetColumnsNames(const std::string& info)
{
	parsingString = info;

	std::transform(parsingString.begin(), parsingString.end(), parsingString.begin(), tolower);
	parsingString.erase(
		std::remove(parsingString.begin(), parsingString.end(), ' '), parsingString.end());

	std::cout << parsingString << '\n';
}
