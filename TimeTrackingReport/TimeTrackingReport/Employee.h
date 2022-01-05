#pragma once
#include <string>
#include "Time.h"

class Employee final
{
public:
	Employee()  = default;
	~Employee() = default;
private:
	std::string name = "";
};

