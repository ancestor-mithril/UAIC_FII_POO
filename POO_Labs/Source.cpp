#include <iostream>
#include "FirstLab.h"


void labOneExOne();
void labOneExTwo();

int main(int argc, const char* argv[])
{
	labOneExOne();
	labOneExTwo();
	return 0;
}


void labOneExOne()
{
	using first_lab::FirstExercise;
	const auto ex = FirstExercise();
	std::cout << "Total sum " << ex.GetSum() << std::endl;
}

void labOneExTwo()
{
	using first_lab::SecondExercise;
	const auto result = SecondExercise().GetWords();
	std::cout << "Sorted words: " << std::endl;
	for (auto& word : result) {
		std::cout << word << std::endl;
	}
	std::cout << std::endl;
}
