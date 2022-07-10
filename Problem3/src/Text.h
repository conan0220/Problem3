#pragma once

#include <fstream>

#include "DataStructure/Vector.h"

class Text
{
public:
	Text();
	Text(const std::string file_path);
	~Text();

	const Vector<std::string>& GetText() { return text; }
	const Vector<int>& GetIntInText();	// int in text

	void ReadFile();	// read .txt file and write in the text
	void PushBack(const std::string& text);
	void SetFilePath(std::string file_path) { this->file_path = file_path; }
	
	void operator += (const std::string& text) { PushBack(text); }

private:

	void UpdateIntInText();
	const int& StringToInt(const std::string& str) const;
	const bool& IsCharInt(const char& ch) const;	// is char int?
	const int& CharToInt(const char& ch) const;
	
	std::string file_path = "";
	Vector<std::string> text = NULL;
	Vector<int> int_in_text = NULL;
	bool is_text_modify = true;
};