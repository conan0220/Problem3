#include "File.h"

#include <string>

File::File()
{
}

File::File(const std::string file_name)
{
	ReadFile(file_name);
}

File::~File()
{
	file.close();
}

void File::ReadFile(std::string file_name) 
{
	file.open(file_name);
	if (file.is_open()) 
	{
		return;
	}
	else 
	{
		std::cerr << "Failed to open file." << std::endl;
		exit(1);
	}
}