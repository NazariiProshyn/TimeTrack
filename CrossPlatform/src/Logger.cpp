/**
 * @file      Logger.cpp
 *
 * @brief     Simple realization of
 *            structure logger
 *
 * @author    Proshyn Nazarii
 * Contact:   nazariyproshyn@gmail.com
 *
 */

#include "Logger.h"
#include <ctime>
#include <sstream>
#include <string>

void Logger::logMessage(const std::string& message)
{
	time_t now = time(nullptr);
	std::tm tm = *std::localtime(&now);
	std::wstringstream wss;
	wss << std::put_time(&tm, L"%F %T");
	std::wstring date = wss.str();
	std::wstring wmessage = std::wstring(message.begin(), message.end());
	fout << date << " " << wmessage << "\n";
}
