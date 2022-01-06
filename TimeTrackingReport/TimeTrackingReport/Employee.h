#pragma once
#include <string>
#include <vector>
#include "Time.h"

class Employee final
{
public:
	Employee()  = default;
	Employee(const std::string& info, const std::string& year, const std::string& month, int hour);
	~Employee() = default;

	const std::string& GetName() const { return name; };
	const std::string& GetAllTime();

	void AddInformation(const std::string& year, const std::string& month, int hour);
private:
	std::string name   = "";
	std::string result = "";
	std::vector<Time> workHours;
};
