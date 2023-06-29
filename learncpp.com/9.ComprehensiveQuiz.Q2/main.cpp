#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

struct studentGrade
{
	std::string firstName{};
	int score{};
};

bool compareByLength(const studentGrade &a, const studentGrade &b)
{
	return a.score > b.score;
}

int main()
{
	std::cout << "How many students do you want to enter? ";
	int numberOfStudents{};
	std::cin >> numberOfStudents;

	std::vector<studentGrade> students{};
	for (int i{ 0 }; i < numberOfStudents; ++i)
	{
		std::cout << "Name: ";
		std::string firstName{};
		std::cin >> firstName;

		std::cout << "Score: ";
		int score{};
		std::cin >> score;

		students.push_back(studentGrade{ firstName, score });
	}

	// This errors because of type
	std::sort(students.begin(), students.end(), compareByLength);

	for (studentGrade student : students)
	{
		std::cout << student.firstName << " got a grade of " << student.score << '\n';
	}
}