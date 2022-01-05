#pragma once
#include <string>
class Time final
{
public:
	Time()  = default;
	~Time() = default;
private:
	unsigned int year = 0;
	unsigned int time = 0;
	std::string month = "";
};

