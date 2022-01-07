#pragma once

/**
 * @file      Logger.h
 *
 * @brief     Simple logger structure
 *
 * @author    Proshyn Nazarii
 * Contact:   nazariyproshyn@gmail.com
 *
 */

#include <string>
#include <fstream>

class Logger final
{
public:
	Logger(const std::string& filePath) :mFilePath(filePath) { fout.open(mFilePath);};
	~Logger() { fout.close(); }

	/**
	 * @brief	Log in file information
	 *
	*/
	void logMessage(const std::string& message);
private:
	std::string mFilePath;
	std::ofstream fout;
};
