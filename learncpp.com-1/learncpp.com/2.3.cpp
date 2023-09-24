#include <iostream>

int doubleNumber(int x)
{
	return x * 2;
}

//int main()
//{
//	std::cout << doubleNumber(18) << '\n';
//}

int getIntegerFromUser()
{
	int x{};
	std::cout << "Enter an integer: ";
	std::cin >> x;

	return x;
}

int main2()
{
	int a{ getIntegerFromUser() };
	std::cout << doubleNumber(a) << '\n';
	return 0;
}