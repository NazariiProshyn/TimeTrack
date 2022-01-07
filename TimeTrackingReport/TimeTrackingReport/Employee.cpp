/**
 * @file      Employee.cpp
 *
 * @brief     Simple realization of
 *            structure Employee
 *
 *
 */

#include "Employee.h"

namespace NSSigns
{
	const char newLine = '\n';
	const char newItem = ';';
	const char space   = ' ';
} 

Employee::Employee(const std::string& info, const std::string& year, const std::string& month, int hour)
{
	name = info; 
	AddInformation(year,month,hour);
}

const std::string& Employee::GetAllTime() 
{
	for (size_t i = 0; i < workHours.size(); i++)
	{
		result += name;
		result += NSSigns::newItem;
		result += workHours[i].GetMonth();
		result += NSSigns::space;
		result += workHours[i].GetYear();
		result += NSSigns::newItem;
		result += std::to_string(workHours[i].GetTime());
		result += NSSigns::newLine;
	}
	return result;
}

void Employee::AddInformation(const std::string& year, const std::string& month, int hour)
{
	bool newInformation = true;
	for (size_t i = 0; i < workHours.size(); ++i)
	{
		if (year  == workHours[i].GetYear() &&
			month == workHours[i].GetMonth())
		{
			workHours[i].AddTime(hour);
			newInformation = false;
		}
	}
	if (newInformation)
	{
		workHours.push_back(Time(year, month, hour));
	}
}
