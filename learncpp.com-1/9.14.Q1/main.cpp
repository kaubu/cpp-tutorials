#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	std::cout << "How many names do you wish to enter? ";
	std::size_t namesAmount{};
	std::cin >> namesAmount;

	std::string *namesArray{ new std::string[namesAmount]{} };

	for (size_t i{ 0 }; i <= namesAmount; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::string name{};
		std::getline(std::cin, name);
		namesArray[i] = name;
	}

	std::sort(std::begin(*namesArray), std::end(*namesArray));

	std::cout << "Here is your sorted list:\n";

	for (size_t i{ 0 }; i < namesAmount; ++i)
	{
		std::cout << "Name #" << i << ": " << namesArray[i] << '\n';
	}

	delete[] namesArray;

	return 0;
}