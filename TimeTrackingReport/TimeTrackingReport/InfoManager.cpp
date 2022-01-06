#include "InfoManager.h"
#include "Exceptions.h"
#include <iostream>
#include <vector>
#include <algorithm>
namespace NSFilesProperties
{
	const std::string typeOfFile = ".csv";
	const std::vector<char> forbiddenSigns =
	{
		'*',
		'"',
		'[',
		']',
		':',
		';',
		'|',
		','
	};
	const int minNumOfColumn = 0;
}
namespace NSMainColumns
{
	const std::string name = "name";
	const std::string day = "date";
	const std::string hour = "loggedhours";
}

void InfoManager::SetFileName()
{
	std::cout << "Input name of file: ";
	std::cin >> fileName;
}

void InfoManager::ReadInformation()
{

	LeadToTheStandard();

	std::cout << "Check the file: " << fileName << '\n';////////////
	fin.open(fileName);
	checkFileRequirements();

	fin.close();
}

void InfoManager::WriteInformation()
{
	resultFileName += fileName;
	fout.open(resultFileName);
	try
	{
		if (!fout.is_open())
		{
			throw Exceptions(resultFileName);
		}
	}
	catch (Exceptions& ex)
	{
		std::cout << ex.getErrorMsg();
	}
	
	for (size_t i = 0; i < employees.size(); ++i)
	{
		fout << employees[i].getAllTime();
	}
	fout.close();
}

void InfoManager::LeadToTheStandard()
{
	for (size_t i = 0; i < NSFilesProperties::forbiddenSigns.size(); ++i)
	{
		fileName.erase(
			std::remove(fileName.begin(), fileName.end(), NSFilesProperties::forbiddenSigns[i]), 
			fileName.end());
	}

	if (!(fileName.find(NSFilesProperties::typeOfFile) != std::string::npos)) {
		fileName += NSFilesProperties::typeOfFile;
	}
	
}

void InfoManager::checkFileRequirements()
{
	try
	{
		if (!fin.is_open())
		{
			throw Exceptions(fileName);
		}
		std::cout << "File open\n";//////////

		getline(fin, readString, '\n');
		parser.SetColumnsNames(readString);

		if (parser.checkName() < NSFilesProperties::minNumOfColumn)
		{
			throw Exceptions(fileName, NSMainColumns::name);
		}
		if (parser.checkHours() < NSFilesProperties::minNumOfColumn)
		{
			throw Exceptions(fileName, NSMainColumns::hour);
		}
		if (parser.checkDay() < NSFilesProperties::minNumOfColumn)
		{
			throw Exceptions(fileName, NSMainColumns::day);
		}
		while (!fin.eof())
		{
			getline(fin, readString, '\n');

			if (readString != "")
			{
				parser.parsInformation(readString);
				if (!parser.checkFormatDate())
				{
					throw Exceptions(fileName, NSMainColumns::day);
				}
				if (!parser.validateHours())
				{
					throw Exceptions(fileName, NSMainColumns::hour);
				}
				manageEmployees();
			}
		}
	}
	catch (Exceptions& ex)
	{
		std::cout << ex.getErrorMsg();
	}
}

void InfoManager::manageEmployees()
{
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

}
