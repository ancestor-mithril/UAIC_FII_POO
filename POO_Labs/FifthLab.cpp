#include "FifthLab.h"

#include <iostream>
#include <string>

#include "CustomException.h"

fifth_lab::Number::Number(const char* value, const int base) : _value(value), _base(base)
{
	if (value[0] == '-')
	{
		_negative = true;
		std::string aux(value + 1);
		_value = std::move(aux);
	}
}

fifth_lab::Number::Number(const int number) : Number(std::to_string(number).c_str(), 10)
{
}


fifth_lab::Number& fifth_lab::Number::operator=(const int number)
{
	_base = 10;
	
	char buffer[33] = { 0 };
	_itoa_s<33>(number, buffer, 10);
	std::string aux(buffer);
	_value = std::move(aux);
	
	return *this;
	
	//TODO: treat negative number;
}

fifth_lab::Number& fifth_lab::Number::operator=(const char* number)
{
	const auto aux = Number(number, 10);
	*this = aux;
	return *this;
}

void fifth_lab::Number::SwitchBase(const int newBase)
{
	//TODO: check if negative numbers have a different base conversion result from positive numbers
	
	const int standardValue = std::stoi(_value, nullptr, _base);
	
	char buffer[33] = { 0 };
	_itoa_s<33>(standardValue, buffer, newBase);
	std::string aux(buffer);
	_value = std::move(aux);
	_base = newBase;
}

void fifth_lab::Number::Print() const
{
	const int sign = _negative ? -1 : 1;
	std::cout << "Number: " << sign * std::stoi(_value, nullptr, _base) << " in base 10, " << (_negative ? "-" : "+") << _value << " in base " << _base << std::endl;
}

int fifth_lab::Number::GetDigitsCount() const
{
	return _value.size();
}

int fifth_lab::Number::GetBase() const
{
	return _base;
}

void fifth_lab::Number::Negate()
{
	_negative = !_negative;
}

bool fifth_lab::Number::operator!() const
{
	return _value == "0" || _value.empty();
}

fifth_lab::Number fifth_lab::Number::operator-() const
{
	Number result(_value.c_str(), _base);
	result.Negate();
	
	return result;
}

char fifth_lab::Number::operator[](const int i) const
{
	if (i < 0 || i >= _value.size())
	{
		throw std::out_of_range("Index out of range exception");
	}
	
	return _value[i];
}

fifth_lab::Number& fifth_lab::Number::operator--()
{
	if (_value.empty())
	{
		throw utils::CustomException("Number is empty");
	}
	
	_value.erase(0, 1);
	return *this;
}

fifth_lab::Number& fifth_lab::Number::operator--(int)
{
	if (_value.empty())
	{
		throw utils::CustomException("Number is empty");
	}
	
	_value.erase(_value.size() - 1, 1);
	return *this;
}

fifth_lab::Number& fifth_lab::Number::operator+=(Number& other)
{
	const auto rez = *this + other;
	*this = rez;
	
	return *this;
}

fifth_lab::Number fifth_lab::operator+(const Number& n1, const Number& n2)
{
	const auto maxBase = std::max(n1._base, n2._base);
	const int value1 = (n1._negative ? -1 : 1) * std::stoi(n1._value, nullptr, n1._base);
	const int value2 = (n2._negative ? -1 : 1) * std::stoi(n2._value, nullptr, n2._base);
	const int sum = value1 + value2;
	
	char buffer[33] = { 0 };
	_itoa_s<33>(sum, buffer, maxBase);

	return Number(buffer, maxBase);
}

fifth_lab::Number fifth_lab::operator-(const Number& n1, const Number& n2)
{
	const auto maxBase = std::max(n1._base, n2._base);
	const int value1 = (n1._negative ? -1 : 1) * std::stoi(n1._value, nullptr, n1._base);
	const int value2 = (n2._negative ? -1 : 1) * std::stoi(n2._value, nullptr, n2._base);
	const int sum = value1 - value2;
	
	char buffer[33] = { 0 };
	_itoa_s<33>(sum, buffer, maxBase);

	return Number(buffer, maxBase);
}

bool fifth_lab::operator>(const Number& n1, const Number& n2)
{
	const int value1 = (n1._negative ? -1 : 1) * std::stoi(n1._value, nullptr, n1._base);
	const int value2 = (n2._negative ? -1 : 1) * std::stoi(n2._value, nullptr, n2._base);
	
	return value1 > value2;
}

bool fifth_lab::operator<(const Number& n1, const Number& n2)
{
	return n2 > n1;
}

bool fifth_lab::operator>=(const Number& n1, const Number& n2)
{
	return !(n1 < n2);
}

bool fifth_lab::operator<=(const Number& n1, const Number& n2)
{
	return !(n1 > n2);
}

bool fifth_lab::operator==(const Number& n1, const Number& n2)
{
	const int value1 = (n1._negative ? -1 : 1) * std::stoi(n1._value, nullptr, n1._base);
	const int value2 = (n2._negative ? -1 : 1) * std::stoi(n2._value, nullptr, n2._base);
	
	return value1 == value2;
}

bool fifth_lab::operator!=(const Number& n1, const Number& n2)
{
	return !(n1 == n2);
}
