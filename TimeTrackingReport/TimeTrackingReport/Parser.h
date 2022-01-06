#pragma once
#include <map>
#include <string>
class Parser final
{
public:
	Parser()  = default;
	~Parser() = default;
	void SetColumnsNames(const std::string& info);
private:
	std::string parsingString = "";

};

