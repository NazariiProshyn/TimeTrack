#pragma once
#include <string>
class Time final
{
public:
	Time()  = default;
	Time(const std::string& year, const std::string& month,int hour);
	~Time() = default;

	const std::string& GetYear()  const { return year; };
	const std::string& GetMonth() const { return month; };

	void AddTime(int info);

	int GetTime() const { return time; };
private:
	std::string year  = "";
	std::string month = "";
	unsigned int time = 0;
	
};
