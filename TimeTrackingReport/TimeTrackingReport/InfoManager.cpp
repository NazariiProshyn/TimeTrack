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
	checkFileRequirements();
	
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
		std::cout << "Check the file: " << fileName << '\n';////////////
		fin.open(fileName);
		if (!fin.is_open())
		{
			throw Exceptions(fileName);
		}
		std::cout << "File open\n";//////////

		std::string readString = "";
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
				std::cout << readString << '\n';
			}

		}
		fin.close();
	}
	catch (Exceptions& ex)
	{
		std::cout << ex.getErrorMsg();
	}
}
