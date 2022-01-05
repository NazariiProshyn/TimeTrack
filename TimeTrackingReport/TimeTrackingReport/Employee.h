#pragma once
#include <string>
#include <vector>
#include "Time.h"

class Employee final
{
public:
	Employee()  = default;
	~Employee() = default;
private:
	std::string name = "";
	std::vector<Time> workHours;
};

