#include "SecondLab.h"

#include <algorithm>
#include <iostream>

#include "CustomException.h"

void second_lab::NumberList::Init()
{
	count = 0;
}

bool second_lab::NumberList::Add(const int x)
{
	if (count >= 10) {
		return false;
	}
	
	numbers[count++] = x;
	return true;
}

void second_lab::NumberList::Sort()
{
	std::sort(numbers, numbers + count);
}

void second_lab::NumberList::Print()
{
	std::cout << "Print numbers: " << std::endl;
	
	for (auto i = 0; i < count; ++i) {
		std::cout << numbers[i] << " ";
	}
	
	std::cout << std::endl;
}

void second_lab::Student::checkGrade(const float grade, const std::string& course) const
{
	if (grade < 1 || grade > 10) {
		throw utils::CustomException(course + " grade must be between 1 and 10, not " + std::to_string(grade));
	}
}

second_lab::Student::Student()
{
	_name = "";
	_englishGrade = 1;
	_historyGrade = 1;
	_mathGrade = 1;
}

second_lab::Student::Student(std::string name) : Student()
{
	_name = std::move(name);
}

float second_lab::Student::MathGrade() const
{
	return _mathGrade;
}

float second_lab::Student::EnglishGrade() const
{
	return _englishGrade;
}

float second_lab::Student::HistoryGrade() const
{
	return _historyGrade;
}

std::string second_lab::Student::Name() const
{
	return _name;
}

void second_lab::Student::SetName(const std::string& name)
{
	_name = name;
}

void second_lab::Student::SetMathGrade(const float mathGrade)
{
	checkGrade(mathGrade, "Math");
	_mathGrade = mathGrade;
}

void second_lab::Student::SetEnglishGrade(const float englishGrade)
{
	checkGrade(englishGrade, "English");
	_englishGrade = englishGrade;
}

void second_lab::Student::SetHistoryGrade(const float historyGrade)
{
	checkGrade(historyGrade, "History");
	_historyGrade = historyGrade;
}

float second_lab::Student::AverageGrade() const
{
	return (_historyGrade + _englishGrade + _mathGrade) / 3;
}

int second_lab::compareName(const Student& st1, const Student& st2)
{
	return strcmp(st1._name.c_str(), st2._name.c_str());
}

int second_lab::compareMathGrade(const Student& st1, const Student& st2)
{
	return st1._mathGrade == st2._mathGrade ? 0 : st1._mathGrade < st2._mathGrade ? -1 : 1;
}

int second_lab::compareEnglishGrade(const Student& st1, const Student& st2)
{
	return st1._englishGrade == st2._englishGrade ? 0 : st1._englishGrade < st2._englishGrade ? -1 : 1;
}

int second_lab::compareHistoryGrade(const Student& st1, const Student& st2)
{
	return st1._historyGrade == st2._historyGrade ? 0 : st1._historyGrade < st2._historyGrade ? -1 : 1;
}

int second_lab::compareAverageGrade(const Student& st1, const Student& st2)
{
	return st1.AverageGrade() == st2.AverageGrade() ? 0 : st1.AverageGrade() < st2.AverageGrade() ? -1 : 1;
}
