#include <iostream>
#include <string>

#include "Text.h"
#include "Vector.h"

Text::Text()
	: is_text_modify(true)
{
}

Text::Text(const std::string file_path)
	: file_path(file_path), is_text_modify(true)
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
	if (is_text_modify)
	{
		UpdateIntInText();		// generate when text be modified
		is_text_modify = false;
	}
	return int_in_text;
}

void Text::push_back(const std::string& text)
{
	this->text += text;
	is_text_modify = true;
}

void Text::operator += (const std::string& text)
{
	push_back(text);
}

void Text::ReadFile() 
{
	std::ifstream file;
	file.open(file_path);

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

void Text::UpdateIntInText()
{
	std::string temp = "";

	for (std::string str : text)
	{
		for (char ch : str)
		{
			if (ch == '-')
			{
				if (temp.empty())
				{
					temp += ch;		// add '-' to first index
				}
				else if (!temp.empty())
				{
					if (*(temp.end() - 1) == '-')
					{
						temp.clear();
						temp += ch;
					}
					else
					{
						int_in_text += StringToInt(temp);
						temp.clear();
						temp += ch;
					}
				}
			}
			else if (IsCharNumber(ch))
			{
				temp += ch;
			}
			else
			{
				if (!temp.empty() && IsCharNumber(*(temp.end() - 1)))
				{
					int_in_text += StringToInt(temp);
					temp.clear();
				}
				else
				{
					temp.clear();
				}
			}
		}
		if (!temp.empty())
		{
			if (*temp.begin() == '-' && temp.length() == 1)
			{
				temp.clear();
			}
			else
			{
				int_in_text += StringToInt(temp);
				temp.clear();
			}
		}
	}
}


const int& Text::StringToInt(const std::string& str) const 
{
	for (char temp : str)
	{
		if (!IsCharNumber(temp) && *str.begin() != '-')
		{
			std::cerr << "[Error]: String is not number" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	int ans = 0;
	if (str[0] == '-') 
	{
		for (int i = str.length() - 1; i >= 1; i--) 
		{
			ans += CharToInt(str[i]) * pow(10, (str.length() - i - 1));
		}
		ans *= -1;
	}
	else 
	{
		for (int i = str.length() - 1; i >= 0; i--) 
		{
			ans += CharToInt(str[i]) * pow(10, (str.length() - i - 1));
		}
	}

	return ans;
}


const bool& Text::IsCharNumber(const char& ch) const 
{
	if (48 <= static_cast<int>(ch) and static_cast<int>(ch) <= 57) 
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
