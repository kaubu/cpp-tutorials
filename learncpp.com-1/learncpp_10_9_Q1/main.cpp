#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int getInteger()
{
	std::cout << "Enter an integer: ";
	int integer{};
	std::cin >> integer;
	
	return integer;
}

char getOperator()
{
	char op{};
	
	do
	{
		std::cout << "Enter an operator (+, -, *, /): ";
		std::cin >> op;
	}
	while(op!='+' && op!='-' && op!='*' && op!='/');
	
	return op;
}

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

ArithmeticFunction getArithmeticFunction(char op)
{
	switch (op)
	{
		case '+':
		{
			return add;
		}
		case '-':
		{
			return subtract;
		}
		case '*':
		{
			return multiply;
		}
		case '/':
		{
			return divide;
		}
	}
}

int main()
{
	int a{ getInteger() };
	char op{ getOperator() };
	int b{ getInteger() };
	
	ArithmeticFunction opFunc{ getArithmeticFunction(op) };
	std::cout << a << ' ' << op << ' ' << b << " = " << opFunc(a, b) << '\n';
	
	return 0;
}
