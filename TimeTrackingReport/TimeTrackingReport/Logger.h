#pragma once
#include <string>
#include <fstream>

class Logger
{
public:
	Logger(const std::string& filePath) :mFilePath(filePath) { fout.open(mFilePath);};
	~Logger() { fout.close(); }
	void logMessage(const std::string& message);
private:
	std::string mFilePath;
	std::ofstream fout;
};
