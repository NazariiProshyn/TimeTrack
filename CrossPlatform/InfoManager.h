#pragma once

/**
 * @file      InfoManager.h
 *
 * @brief     Structure to manage information
 *
 * @author    Proshyn Nazarii
 * Contact:   nazariyproshyn@gmail.com
 *
 */

#include <string>
#include <fstream>
#include "Employee.h"
#include "Parser.h"
#include "Logger.h"

namespace NSLogger {
	static const std::string path      = "Log.txt";
	static const std::string openFile  = "File open: ";
	static const std::string readInfo  = "Read information: ";
	static const std::string writeInfo = "Write information: ";
	static const std::string closeFile = "File close: ";
	static const std::string invalidD  = "Invalid data: ";
	static const std::string cantOpen  = "Can't open file: ";
}

class InfoManager final
{
public:
	InfoManager() : logger(NSLogger::path) {};
	~InfoManager() = default;

	/**
	 * @brief	sets the path to the file
	 *
	*/
	void SetFileName();

	/**
	 * @brief	read and format 
	 *			information from a file
	 *
	*/
	void ReadInformation();

	/**
	* @brief	write information to a file
	*
	*/
	void WriteInformation();
private:
	/**
	 * @brief	format information to
	 *          standard that easy to handle
	 *
	*/
	void LeadToTheStandard();

	/**
	 * @brief	checks the file 
	 *          for major elements
	 *			(in any order)
	 *
	*/
	void CheckFileRequirements();

	/**
	 * @brief	Add new employee 
	 *			or add information about
	 *
	*/
	void ManageEmployees();

	std::string readString = "";
	std::string fileName   = "";
	std::string resultFileName = "result";
	std::ifstream fin;
	std::ofstream fout;

	std::vector<Employee> employees;
	Parser parser;
	Logger logger;
};
