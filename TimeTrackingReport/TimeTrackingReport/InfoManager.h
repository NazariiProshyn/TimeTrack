#pragma once
#include <string>
class InfoManager final
{
public:
	InfoManager()  = default;
	~InfoManager() = default;
	void SetFileName();
	void ReadInformation();
private:
	void LeadToTheStandard();
	std::string fileName = "";
};

