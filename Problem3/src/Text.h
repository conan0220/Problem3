#pragma once
#include <fstream>

#include "Vector.h"

class Text
{
public:
	Text();
	Text(const std::string file_path);
	~Text();

	
	const Vector<std::string>& get_text();
	const Vector<int>& get_int();	// number in text

	void push_back(const std::string& text);

	void operator += (const std::string& text);

private:
	void ReadFile();	// read .txt file and write in the text
	void UpdateIntInText();
	const int& StringToInt(const std::string& str) const;
	const bool& IsCharNumber(const char& ch) const;	// is char number or '-'
	const int& CharToInt(const char& ch) const;
	
	std::string file_path;
	Vector<std::string> text;
	Vector<int> int_in_text;
	bool is_text_modify;
};