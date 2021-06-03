#include <algorithm>
#include <iostream>

#include "FifthLab.h"
#include "FirstLab.h"
#include "FourthLab.h"
#include "SecondLab.h"
#include "SeventhLab.h"
#include "SixthLab.h"
#include "ThirdLab.h"


void labOneExOne();
void labOneExTwo();
void labTwoExOne();
void labTwoExTwo();
void labThreeExOne();
void labThreeExTwo();
void labFour();
void labFive();
void labSix();
void labSeventhExOne();
void labSeventhExTwo();

int main(int argc, const char* argv[])
{
	labOneExOne();
	labOneExTwo();
	labTwoExOne();
	labTwoExTwo();
	labThreeExOne();
	labThreeExTwo();
	labFour();
	labFive();
	labSix();
	labSeventhExOne();
	labSeventhExTwo();
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
	std::cout << a << " + " << b << " + " << c << " = " << Math::Add(a, b, c) << std::endl;
	std::cout << d << " + " << e << " = " << Math::Add(d, e) << std::endl;
	std::cout << d << " + " << e << " + " << f << " = " << Math::Add(d, e, f) << std::endl;
	std::cout << a << " + " << b << " = " << Math::Mul(a, b) << std::endl;
	std::cout << a << " + " << b << " + " << c << " = " << Math::Mul(a, b, c) << std::endl;
	std::cout << d << " + " << e << " = " << Math::Mul(d, e) << std::endl;
	std::cout << d << " + " << e << " + " << f << " = " << Math::Mul(d, e, f) << std::endl;
	std::cout << a << " + " << b << " + " << c << " + " << d << " + " << e << " + " << f << " = " << Math::Add(6, a, b, c, d, e, f) << std::endl;

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
	canvas.SetPoint(5, 5, '*');
	canvas.Print();
	canvas.Clear();

	std::cout << "Drawing line: " << std::endl;
	canvas.DrawLine(2, 2, 8, 8, '*');
	canvas.Print();
	canvas.Clear();
}

void labFour()
{
	using forth_lab::Sort;
	const std::vector<int> vector = { 1, 5, 2, 4, 5, 6, 3 };
	int array[] = { 7, 3, 5, 6, 3, 4, 6, 2 };

	Sort v1(10, 2, 100);
	Sort v2(vector);
	Sort v3(array, 8);
	Sort v4({ 1, 3, 5,3 ,1 , 4, 3 });

	std::string string("10,40,100,5,70");
	Sort v5(string);

	std::cout << std::endl << "v1" << std::endl;
	v1.Print();

	v1.BubbleSort();
	v1.Print();

	std::cout << std::endl << "v2" << std::endl;
	v2.Print();

	v2.QuickSort();
	v2.Print();

	std::cout << std::endl << "v3" << std::endl;
	v3.Print();

	v3.InsertSort();
	v3.Print();

	std::cout << std::endl << "v4" << std::endl;
	v4.Print();

	v4.BubbleSort();
	v4.Print();

	std::cout << std::endl << "v5" << std::endl;
	v5.Print();

	v5.BubbleSort();
	v5.Print();
}

void labFive()
{
	using fifth_lab::Number;
	Number n1("10110010", 2);
	Number n2("734", 8);
	Number n3("FF", 16);

	printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
	for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
	{
		printf("n1[%d]=%c\n", tr, n1[tr]);
	}
	n1.Print();
	n2.Print();
	n1 = (n2 + n3 - n1) + n1; // after this n1 will be in base 16
	n1.SwitchBase(2);
	n1.Print();

	if (n1 > n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");

	Number n4 = 12345; // n4 will be in base 10
	n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
	n4 += n1;
	n4.Print();

	n4 = "13579"; // n4 mentains its base (10) and will be 13579
	n4.Print();
	--n4; // the first digit from n4 will be remove ==> n4 becomes 3579
	n4.Print();
	n4--; // the last digit from n4 will be remove ==> n4 becomes 357
	n4.Print();
}

void labSix()
{
	using sixth_lab::Circuit;
	using sixth_lab::Weather;
	using sixth_lab::Dacia;
	using sixth_lab::Toyota;
	using sixth_lab::Mazda;
	using sixth_lab::Mercedes;
	using sixth_lab::Ford;

	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinis(); // it is possible that some cars don't have enough fuel to finish the circuit
}

void labSeventhExOne()
{
	using seventh_lab::operator ""_Fahrenheit;
	using seventh_lab::operator ""_Kelvin;
	using seventh_lab::Degree;

	const float a = static_cast<float>(300_Kelvin);
	const float b = static_cast<float>(120_Fahrenheit);

	std::cout << "300 Kelvin = " << a << " Celsius" << '\n';
	std::cout << "120 Fahrenheit = " << b << " Celsius" << '\n';
	std::cout << '\n';
}

void labSeventhExTwo()
{
	using seventh_lab::TemplateVector;
	TemplateVector<int> vector;

	vector.Push(10);
	vector.Push(10);
	vector.Push(11);
	vector.Push(11);
	vector.Push(9);
	vector.Push(9);
	vector.Push(9);

	vector.Pop();
	vector.Print();

	vector.Delete(0);
	vector.Print();

	vector.Insert(10, 1);
	vector.Print();

	vector.Sort();
	vector.Print();

	vector.Set(11, 0);
	std::cout << vector.Get(0) << "\n";
	std::cout << vector.Count() << "\n";
	std::cout << vector.FirstIndexOf(10) << "\n";
	std::cout << "\n";
}
