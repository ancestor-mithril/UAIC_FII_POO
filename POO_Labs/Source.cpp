#include <iostream>
#include "FirstLab.h"
#include "SecondLab.h"


void labOneExOne();
void labOneExTwo();
void labTwoExOne();
void labTwoExTwo();

int main(int argc, const char* argv[])
{
	labOneExOne();
	labOneExTwo();
	labTwoExOne();
	labTwoExTwo();
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

void labTwoExOne()
{
	second_lab::NumberList numberList;
	numberList.Init();
	numberList.Add(1);
	numberList.Add(51);
	numberList.Add(12);
	numberList.Sort();
	numberList.Print();
}

void labTwoExTwo()
{
	using second_lab::Student;
	auto st1 = Student("Name1");
	st1.SetEnglishGrade(8);
	st1.SetHistoryGrade(7);
	st1.SetMathGrade(10);
	auto st2 = Student("Name2");
	st2.SetEnglishGrade(8);
	st2.SetHistoryGrade(6);
	st2.SetMathGrade(10);
	std::cout << "Name comparison: " << st1.Name() << " ? " << st2.Name() << " -> " << compareName(st1, st2) << std::endl;
	std::cout << "Math grade comparison: " << st1.MathGrade() << " ? " << st2.MathGrade() << " -> " << compareMathGrade(st1, st2) << std::endl;
	std::cout << "History grade comparison: " << st1.HistoryGrade() << " ? " << st2.HistoryGrade() << " -> " << compareHistoryGrade(st1, st2) << std::endl;
	std::cout << "English grade comparison: " << st1.EnglishGrade() << " ? " << st2.EnglishGrade() << " -> " << compareEnglishGrade(st1, st2) << std::endl;
	std::cout << "Average grade comparison: " << st1.AverageGrade() << " ? " << st2.AverageGrade() << " -> " << compareAverageGrade(st1, st2) << std::endl;
}