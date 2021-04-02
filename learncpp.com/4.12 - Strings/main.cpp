#include <iostream>
#include <string>

//int main()
//{
//	std::cout << "Enter your full name: ";
//	std::string name{};
//	std::getline(std::cin, name);
//
//	std::cout << "Enter your age: ";
//	std::string age{};
//	std::getline(std::cin, age);
//
//	std::cout << "Your name is " << name << " and your age is " << age << '\n';
//
//	return 0;
//}

//int main()
//{
//	std::cout << "Pick 1 or 2: ";
//	int choice{};
//	std::cin >> choice;
//
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//	std::cout << "Now enter your name: ";
//	std::string name;
//	std::getline(std::cin, name);
//
//	std::cout << "Hello, " << name << ", you picked " << choice << '\n';
//
//	return 0;
//}

int main()
{
	std::string myName{ "Alex" };
	std::cout << myName << " has " << myName.length() << " characters\n";
	return 0;
}