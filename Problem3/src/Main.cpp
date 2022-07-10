#include "Problem3.h"

int main()
{
	std::string filepath = "";

	std::cout << "Input File: ";
	std::cin >> filepath;

	Problem3 problem(filepath);

	std::cin.get();
}