#include "Logger.h"
#include <ctime>

void Logger::logMessage(const std::string& message)
{
		time_t now = time(nullptr);
		char dateBuffer[50];
		ctime_s(dateBuffer, sizeof(dateBuffer), &now);
		fout << dateBuffer << message << "\n";
}
