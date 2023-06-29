#include <string>
#include <iostream>

int main()
{
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;

	std::cout << "What is your age? ";
	int age;
	std::cin >> age;

	std::cout << "My name is " << name << " and I am " << age << " years old.\n";
}