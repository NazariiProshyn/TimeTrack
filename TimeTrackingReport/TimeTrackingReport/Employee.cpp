#include "Employee.h"

Employee::Employee(const std::string& info, const std::string& year, const std::string& month, int hour)
{
	name = info; 
	addInformation(year,month,hour);
}

void Employee::addInformation(const std::string& year, const std::string& month, int hour)
{

}
/*
	bool newEmployee = true;
	for (size_t i = 0; i < employees.size(); ++i)
	{
		if (parser.getName() == employees[i].getName())
		{
			employees[i].addInformation(parser.getYear(), parser.getMonth(), parser.getHour());
			newEmployee = false;
		}
	}
	if (newEmployee)
	{
		std::cout << parser.getName() << '\n';
		employees.push_back(Employee(parser.getName(), parser.getYear(),
			parser.getMonth(), parser.getHour()));
	}


*/