#pragma once
#include <string>
class Time final
{
public:
	Time()  = default;
	~Time() = default;
private:
	std::string year  = "";
	std::string month = "";
	unsigned int time = 0;
	
};

