#include <iostream>
#include <random>
#include <ctime>

namespace MyRandom
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int getRandomNumber(int min, int max)
{
	std::uniform_int_distribution die{ min, max };
	return die(MyRandom::mersenne);
}

int main()
{
	std::cout << getRandomNumber(1, 6) << '\n';
	std::cout << getRandomNumber(1, 10) << '\n';
	std::cout << getRandomNumber(1, 20) << '\n';

	return 0;
}