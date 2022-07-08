#include "Text.h"
#include "Vector.h"

int main()
{
	Text new_text("res/test1.txt");
	for (auto temp : new_text.get_text())
	{
		std::cout << temp << std::endl;
	}
}