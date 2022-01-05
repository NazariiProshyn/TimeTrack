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


InfoManager::InfoManager()
{
	fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
}

void InfoManager::SetFileName()
{
	std::cout << "Input name of file: ";
	std::cin >> fileName;
}

void InfoManager::ReadInformation()
{
	LeadToTheStandard();
	std::cout << "Check the file: " << fileName << '\n';

	try
	{
		fin.open(fileName);
		std::cout << "File open\n";
	}
	catch (const std::ifstream::failure& ex)
	{
		std::cout << ex.what()
			<<"\nCan't find file with name: " << fileName <<'\n';
	}


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
