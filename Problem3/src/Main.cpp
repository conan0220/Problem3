#include "Text.h"
#include "Vector.h"

int main()
{
	Text new_text("res/test_29.txt");
	for (auto temp : new_text.get_int())
	{
		std::cout << temp << std::endl;
	}
}