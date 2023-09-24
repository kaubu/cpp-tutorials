#include <iostream>

void printCStyleString(const char cArray[])
{
	int counter{ 0 };
	while (true)
	{
		if (cArray[counter] == '\0')
		{
			std::cout << '\n';
			break;
		}

		std::cout << cArray[counter];

		++counter;
	}
}

int main()
{
	const char *str{ "Hello World!" };
	printCStyleString(str);

	return 0;
}