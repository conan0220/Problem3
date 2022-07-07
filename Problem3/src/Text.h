#pragma once
#include <fstream>

#include "Vector.h"

class Text
{
public:
	Text(const std::string file_name);
	~Text();

	
	const Vector<std::string>& get_text();
	const Vector<int>& get_int();	// number in text

private:
	void ReadFile();	// read .txt file and write in the text
	void GenerateIntInText();
	const int& StringToInt(const std::string& word) const;
	const bool& IsCharNumber(const char& ch) const;	// is char number or '-'
	const int& CharToInt(const char& ch) const;
	
	std::string file_name;
	Vector<std::string> text;
	Vector<int> int_in_text;
};