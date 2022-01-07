#pragma once

/**
 * @file      Employee.h
 *
 * @brief     Simple structure of employee
 *
 *
 */

#include <string>
#include <vector>
#include "Time.h"

class Employee final
{
public:
	Employee()  = default;
	Employee(const std::string& info, const std::string& year, const std::string& month, int hour);
	~Employee() = default;

	/**
	 * @brief	Returns employee's name.
	 *
	 * @return  Name of employee.
	*/
	const std::string& GetName() const { return name; };

	/**
	 * @brief	Union all information about
	 *			activity of the worker
	 *
	 * @return  Information about activity of worker
	 *          (by years, months)
	*/
	const std::string& GetAllTime();

	/**
	 * @brief		Add information about activity
	 *				of worker
	 *
	 * @param year	year of activity
	 *		  month month of activity
	 *        hour  length of activity
	 * 
	*/
	void AddInformation(const std::string& year, const std::string& month, int hour);
private:
	std::string name   = "";
	std::string result = "";
	std::vector<Time> workHours;
};
