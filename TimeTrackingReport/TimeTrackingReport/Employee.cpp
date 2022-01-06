#include "Employee.h"

namespace NSSigns
{
	const char newLine = '\n';
	const char newItem = ';';
	const char space    = ' ';
} 

Employee::Employee(const std::string& info, const std::string& year, const std::string& month, int hour)
{
	name = info; 
	addInformation(year,month,hour);
}

const std::string& Employee::getAllTime()
{
	for (size_t i = 0; i < workHours.size(); i++)
	{
		result += name;
		result += NSSigns::newItem;
		result += workHours[i].getMonth();
		result += NSSigns::space;
		result += workHours[i].getYear();
		result += NSSigns::newItem;
		result += std::to_string(workHours[i].getTime());
		result += NSSigns::newLine;
	}
	return result;
}

void Employee::addInformation(const std::string& year, const std::string& month, int hour)
{
	bool newInformation = true;
	for (size_t i = 0; i < workHours.size(); ++i)
	{
		if (year == workHours[i].getYear() &&
			month == workHours[i].getMonth())
		{
			workHours[i].addTime(hour);
			newInformation = false;
		}
	}
	if (newInformation)
	{
		workHours.push_back(Time(year, month, hour));
	}
}
