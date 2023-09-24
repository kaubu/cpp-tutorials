#include <iostream>

int main()
{
	std::cout << "Enter a double value: ";
	double x{};
	std::cin >> x;

	std::cout << "Enter a double value: ";
	double y{};
	std::cin >> y;

	std::cout << "Enter one of the following: +, -, *, or /: ";
	char symbol{};
	std::cin >> symbol;

	double answer{};
	if (symbol == '+')
	{
		answer = x + y;
	}
	else if (symbol == '-')
	{
		answer = x - y;
	}
	else if (symbol == '*')
	{
		answer = x * y;
	}
	else if (symbol == '/')
	{
		answer = x / y;
	}
	else
	{
		return 1;
	}

	std::cout << x << " " << symbol << " " << y << " is " << answer;

	return 0;
}