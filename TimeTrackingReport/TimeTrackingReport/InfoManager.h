#pragma once
#include <string>
class InfoManager final
{
public:
	InfoManager()  = default;
	~InfoManager() = default;
	void setFileName();
private:
	std::string fileName = "";
};

