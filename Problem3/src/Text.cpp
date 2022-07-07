#include <iostream>
#include <string>

#include "Text.h"
#include "Vector.h"

Text::Text(const std::string file_name)
	: file_name(file_name)
{
	ReadFile();
}

Text::~Text()
{
}

const Vector<std::string>& Text::get_text()
{
	return text;
}

const Vector<int>& Text::get_int()
{
	static bool once = true;
	if (once)
	{
		GenerateIntInText();		// generate only when get_int first time
		once = false;
	}
	return int_in_text;
}

void Text::ReadFile() 
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
		std::cerr << "[Error]: Failed to open file." << std::endl;
		exit(EXIT_FAILURE);
	}

	file.close();
}

void Text::GenerateIntInText()
{
	std::string temp = "";

	for (std::string str : text)
	{
		for (char ch : str)
		{
			if (ch == '-' || IsCharNumber(ch))
			{
				temp += ch;
			}
			else if (!temp.empty())
			{
				int_in_text += StringToInt(temp);
				temp.clear();
			}
			else
			{
				continue;
			}
		}
	}
}


const int& Text::StringToInt(const std::string& word) const {
	for (char temp : word)
	{
		if (!IsCharNumber(temp))
		{
			std::cerr << "[Error]: String is not number" << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	int ans = 0;

	if (word[0] == '-') {
		for (int i = word.length() - 1; i >= 1; i--) {
			ans += CharToInt(word[i]) * pow(10, (word.length() - i - 1));
		}
		ans *= -1;
	}
	else {
		for (int i = word.length() - 1; i >= 0; i--) {
			ans += CharToInt(word[i]) * pow(10, (word.length() - i - 1));
		}
	}

	return ans;
}


const bool& Text::IsCharNumber(const char& ch) const 
{
	if (ch == '-' or 48 <= static_cast<int>(ch) and static_cast<int>(ch) <= 57) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

const int& Text::CharToInt(const char& ch) const
{
	if (!IsCharNumber(ch))
	{
		std::cerr << "[Error]: Char is not number" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		return static_cast<int>(ch) - 48;
	}
}
