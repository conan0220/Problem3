#include <iostream>
#include <string>

#include "Text.h"
#include "DataStructure/Vector.h"

Text::Text() {}

Text::Text(const std::string file_path)
	: file_path(file_path)
{
	ReadFile();
}

Text::~Text() {}

const Vector<int>& Text::GetIntInText()
{
	if (is_text_modify)
	{
		UpdateIntInText();		// generate when text be modified
		is_text_modify = false;
	}
	return int_in_text;
}

void Text::ReadFile()
{
	std::ifstream file(file_path);
	std::string line_text = "";
	text.Resize(0);
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

void Text::PushBack(const std::string& text)
{
	this->text += text;
	is_text_modify = true;
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
			else if (IsCharInt(ch))
			{
				temp += ch;
			}
			else
			{
				if (!temp.empty() && IsCharInt(*(temp.end() - 1)))
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
		if (!IsCharInt(temp) && *str.begin() != '-')
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

const bool& Text::IsCharInt(const char& ch) const 
{
	return 48 <= static_cast<int>(ch) && static_cast<int>(ch) <= 57 ? true : false;
}

const int& Text::CharToInt(const char& ch) const
{
	if (!IsCharInt(ch))
	{
		std::cerr << "[Error]: Char is not number" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		return static_cast<int>(ch) - 48;
	}
}
