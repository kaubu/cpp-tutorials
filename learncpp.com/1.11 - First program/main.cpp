#include <iostream>

// 1.11
int old()
{
	std::cout << "Enter an integer: ";

	int num{ 0 };
	std::cin >> num;

	std::cout << "Double " << num << " is: " << num * 2 << '\n';

	std::cout << "Double " << num << " is: " << num * 3 << '\n';
	
	return 0;
}

// For the project at the end of 1.x
int main()
{
	std::cout << "Enter an integer: ";

	int firstNum{ 0 };
	std::cin >> firstNum;

	std::cout << "Enter another integer: ";

	int secondNum{ 0 };
	std::cin >> secondNum;

	std::cout << firstNum << " + " << secondNum << " is " << firstNum + secondNum << ".\n";

	std::cout << firstNum << " - " << secondNum << " is " << firstNum - secondNum << ".\n";

	return 0;
}