#pragma once
#include <string>
class Time final
{
public:
	Time()  = default;
	Time(const std::string& year, const std::string& month,int hour);
	~Time() = default;
	const std::string& getYear()  { return year; };
	const std::string& getMonth() { return month; };
	void addTime(int info);

	int getTime() { return time; };
private:
	std::string year  = "";
	std::string month = "";
	unsigned int time = 0;
	
};

