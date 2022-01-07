#pragma once

/**
 * @file      Time.h
 *
 * @brief     Simple time handling structure
 *
 * @author    Proshyn Nazarii
 * Contact:   nazariyproshyn@gmail.com
 *
 */

#include <string>
class Time final
{
public:
	Time()  = default;
	Time(const std::string& year, const std::string& month,int hour);
	~Time() = default;

	/**
	 * @brief	Returns year of data tracking.
	 *
	 * @return  Year of data tracking.
	*/
	const std::string& GetYear()  const { return year; };

	/**
	 * @brief	Returns month of data tracking.
	 *
	 * @return  Month of data tracking.
	*/
	const std::string& GetMonth() const { return month; };

	/**
	* @brief	   Add time to hours worked.
	*
	* @param info  Time to add
	*/
	void AddTime(int info);

	/**
	 * @brief	Returns values of hours worked.
	 *
	 * @return  Values of hours worked.
	*/
	int GetTime() const { return time; };
private:
	std::string year  = "";
	std::string month = "";
	unsigned int time = 0;
	
};
