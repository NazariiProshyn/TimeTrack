/**
 * @file      Time.cpp
 *
 * @brief     Simple realization of
 *            time handling structure
 *
 *
 */

#include "Time.h"

namespace NSConstants
{
	const int hoursInDay = 24;
}

Time::Time(const std::string& year, const std::string& month, int hour)
{
	this->year  = year;
	this->month = month;
	this->time  = hour;
}

void Time::AddTime(int info)
{
	time += info;
	if (time > NSConstants::hoursInDay)
	{
		time = NSConstants::hoursInDay;
	}
}
