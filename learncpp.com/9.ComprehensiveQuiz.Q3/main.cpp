#include <iostream>

void swap(int &a, int &b)
{
	int c{ a };
	int d{ b };
	a = d;
	b = c;
}

int main()
{
	int a{ 5 };
	int b{ 6 };

	std::cout << "a: " << a << '\t' << "b: " << b << '\n';

	swap(a, b);

	std::cout << "a: " << a << '\t' << "b: " << b << '\n';

	return 0;
}