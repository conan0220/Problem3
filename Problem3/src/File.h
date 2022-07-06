#pragma once
#include <fstream>

#include "Vector.h"

class File
{
public:
	File(const std::string file_name);
	~File();

	void ReadFile();	// read .txt file and write to text
	void GetText();

private:

	std::string file_name;
	Vector<std::string> text;
};