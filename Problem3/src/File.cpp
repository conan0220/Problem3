#include <iostream>
#include <string>

#include "File.h"
#include "Vector.h"

File::File(const std::string file_name)
	: file_name(file_name)
{
	ReadFile();
}

File::~File()
{
	
}

void File::ReadFile() 
{
	std::ifstream file;
	file.open(file_name);

	std::string line_text = "";
	if (file.is_open()) 
	{
		while (std::getline(file, line_text))
		{
			text += line_text;
		}
	}
	else 
	{
		std::cerr << "Failed to open file." << std::endl;
		exit(1);
	}

	file.close();
}

void File::GetText()
{
	for (auto temp : text)
	{
		std::cout << temp << std::endl;
	}
}
