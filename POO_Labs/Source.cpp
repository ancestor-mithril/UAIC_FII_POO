#include <iostream>
#include "FirstLab.h"
#include "SecondLab.h"
#include "ThirdLab.h"


void labOneExOne();
void labOneExTwo();
void labTwoExOne();
void labTwoExTwo();
void labThreeExOne();
void labThreeExTwo();

int main(int argc, const char* argv[])
{
	labOneExOne();
	labOneExTwo();
	labTwoExOne();
	labTwoExTwo();
	labThreeExOne();
	labThreeExTwo();
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

void labThreeExOne()
{
	using third_lab::Math;
	const int a = 2, b = 3, c = 4;
	const double d = 1.4, e = 3.7, f = 5.6;
	std::cout << a << " + " << b << " = " << Math::Add(a, b) << std::endl;
	std::cout << a << " + " << b <<" + " << c << " = " << Math::Add(a, b, c) << std::endl;
	std::cout << d << " + " << e << " = " << Math::Add(d, e) << std::endl;
	std::cout << d << " + " << e <<" + " << f << " = " << Math::Add(d, e, f) << std::endl;
	std::cout << a << " + " << b << " = " << Math::Mul(a, b) << std::endl;
	std::cout << a << " + " << b <<" + " << c << " = " << Math::Mul(a, b, c) << std::endl;
	std::cout << d << " + " << e << " = " << Math::Mul(d, e) << std::endl;
	std::cout << d << " + " << e <<" + " << f << " = " << Math::Mul(d, e, f) << std::endl;
	std::cout << a << " + " << b << " + " << c << " + " << d << " + " << e <<" + " << f << " = " << Math::Add(6, a, b, c, d, e, f) << std::endl;
	const auto sir1 = "sir1";
	const auto sir2 = "sir2";
	const char* const sir3 = nullptr;
	const auto result1 = Math::Add(sir1, sir2);
	const auto result2 = Math::Add(sir1, sir3);
	std::cout << sir1 << " + " << sir2 << " = " << (result1 == nullptr ? "nullptr" : result1) << std::endl;
	std::cout << sir1 << " + " << "nullptr" << " = " << (result2 == nullptr ? "nullptr" : result2) << std::endl;
}

void labThreeExTwo()
{
	using third_lab::Canvas;
	Canvas canvas(10, 20);
	std::cout << "Drawing circle: " << std::endl;
	canvas.DrawCircle(5, 5, 3, '*');
	canvas.Print();
	canvas.Clear();
	std::cout << "Filling circle: " << std::endl;
	canvas.FillCircle(5, 5, 3, '*');
	canvas.Print();
	canvas.Clear();
	std::cout << "Drawing rectangle: " << std::endl;
	canvas.DrawRect(2, 2, 8, 8, '*');
	canvas.Print();
	canvas.Clear();
	std::cout << "Filling rectangle: " << std::endl;
	canvas.FillRect(2, 2, 8, 8, '*');
	canvas.Print();
	canvas.Clear();
	std::cout << "Setting point: " << std::endl;
	canvas.SetPoint(5, 5,  '*');
	canvas.Print();
	canvas.Clear();
	std::cout << "Drawing line: " << std::endl;
	canvas.DrawLine(2, 2, 8, 8, '*');
	canvas.Print();
	canvas.Clear();
}
