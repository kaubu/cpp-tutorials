#include <iostream>

void doNothing(int&)
{
}

int main()
{
	int x;

	doNothing(x);

	std::cout << x;

	return 0;
}
