#include <iostream>
#include <random>
#include <ctime>

int main()
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::uniform_int_distribution die{ 1, 6 };

	for (int count{ 1 }; count <= 48; ++count)
	{
		std::cout << die(mersenne) << '\t';

		if (count % 6 == 0)
		{
			std::cout << '\n';
		}
	}

	return 0;
}