#pragma once
#include <string>
#include <fstream>
class InfoManager final
{
public:
	InfoManager();
	~InfoManager() = default;
	void SetFileName();
	void ReadInformation();
private:
	void LeadToTheStandard();
	std::string fileName = "";
	std::ifstream fin;
};

