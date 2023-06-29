#include <iostream>

int main()
{
	int someInt{ 1 };
	int *somePtr{ &someInt };
	someInt = 5;
	std::cout << *somePtr;

	/*int someOtherInt{ someInt };
	someInt = 5;
	std::cout << someOtherInt;*/

	return 0;
}
