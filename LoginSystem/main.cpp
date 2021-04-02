#include <iostream>
#include <fstream>
#include <string>

bool isLoggedIn()
{
	std::cout << "Enter username: ";
	std::string username{};
	std::cin >> username;

	std::cout << "Enter password: ";
	std::string password{};
	std::cin >> password;

	std::ifstream read(username + ".txt");

	std::string un{};
	std::getline(read, un);

	std::string pw{};
	std::getline(read, pw);

	if (un == username && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	std::cout << "1: Register\n2. Login\n>> ";
	int choice{};
	std::cin >> choice;

	switch (choice)
	{
		case 1:
		{
			std::cout << "Select a username: ";
			std::string username{};
			std::cin >> username;

			std::cout << "Select a password: ";
			std::string password{};
			std::cin >> password;

			std::ofstream file{};
			file.open(username + ".txt", std::fstream::out);
			file << username << '\n' << password;
			file.close();

			main();
		}
		case 2:
		{
			bool status{ isLoggedIn() };

			if (!status)
			{
				std::cout << "Incorrect login!\n";
				system("PAUSE");
				return 1;
			}
			else
			{
				std::cout << "Successfully logged in!\n";
				system("PAUSE");
				return 0;
			}
		}
		default:
		{
			std::cout << "That wasn't an option!\n";
			return 1;
		}
	}
}