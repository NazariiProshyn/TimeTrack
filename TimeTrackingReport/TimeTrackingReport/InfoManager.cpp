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
	const std::string name = "Name";
	const std::string day  = "Date";
	const std::string hour = "Total hours";
	const std::string tableHeader =
		"Name;Date;Total hours\n";
}

void InfoManager::SetFileName()
{
	std::cout << "Input name of file: ";
	std::cin  >> fileName;
}

void InfoManager::ReadInformation()
{

	LeadToTheStandard();

	std::cout << "Check the file: " << fileName << '\n';////////////
	fin.open(fileName);
	CheckFileRequirements();

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
		std::cout << ex.GetErrorMsg();
	}
	fout << NSMainColumns::tableHeader;
	for (size_t i = 0; i < employees.size(); ++i)
	{
		fout << employees[i].GetAllTime();
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

void InfoManager::CheckFileRequirements()
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

		if (parser.CheckName() < NSFilesProperties::minNumOfColumn)
		{
			throw Exceptions(fileName, NSMainColumns::name);
		}
		if (parser.CheckHours() < NSFilesProperties::minNumOfColumn)
		{
			throw Exceptions(fileName, NSMainColumns::hour);
		}
		if (parser.CheckDay() < NSFilesProperties::minNumOfColumn)
		{
			throw Exceptions(fileName, NSMainColumns::day);
		}

		while (!fin.eof())
		{
			getline(fin, readString, '\n');

			if (readString != "")
			{
				parser.ParsInformation(readString);
				if (!parser.CheckFormatDate())
				{
					throw Exceptions(fileName, NSMainColumns::day);
				}
				if (!parser.ValidateHours())
				{
					throw Exceptions(fileName, NSMainColumns::hour);
				}
				ManageEmployees();
			}
		}
	}
	catch (Exceptions& ex)
	{
		std::cout << ex.GetErrorMsg();
	}
}

void InfoManager::ManageEmployees()
{
	bool newEmployee = true;
	for (size_t i = 0; i < employees.size(); ++i)
	{
		if (parser.GetName() == employees[i].GetName())
		{
			employees[i].AddInformation(parser.GetYear(), parser.GetMonth(), parser.getHour());
			newEmployee = false;
		}
	}
	if (newEmployee)
	{
		std::cout << parser.GetName() << '\n';
		employees.push_back(Employee(parser.GetName(), parser.GetYear(),
			parser.GetMonth(), parser.getHour()));
	}

}
