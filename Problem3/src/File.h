#pragma once

#include <iostream>
#include <fstream>

class File
{
public:

	File();
	File(const std::string file_name);
	~File();

	void ReadFile(std::string file_name);	// read .txt file

private:


	std::ifstream file;
};