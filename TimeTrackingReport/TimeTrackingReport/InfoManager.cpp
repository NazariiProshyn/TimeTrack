#include "InfoManager.h"
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
}


void InfoManager::SetFileName()
{
	std::cout << "Input name of file: ";
	std::cin >> fileName;
}

void InfoManager::ReadInformation()
{
	LeadToTheStandard();
	std::cout << "Check the file: " << fileName;


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
