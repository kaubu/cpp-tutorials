#include <iostream>

int main()
{
	/*int v{ 5 };
	int *ptr{ &v };

	std::cout << &v << '\n';
	std::cout << ptr << '\n';*/

	int value{ 5 };
	std::cout << &value << '\n';
	std::cout << value << '\n';

	int *ptr{ &value };
	std::cout << ptr << '\n';
	std::cout << *ptr << '\n';

	return 0;
}