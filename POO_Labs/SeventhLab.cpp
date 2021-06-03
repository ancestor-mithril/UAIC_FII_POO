#include "SeventhLab.h"

seventh_lab::Degree::Degree(const double value) : _value(value) {
}

seventh_lab::Degree::operator float() const
{
	return static_cast<float>(_value);
}

seventh_lab::Degree seventh_lab::operator ""_Kelvin(const unsigned long long value)
{
	return Degree(static_cast<double>(value) - 273.15);
}

seventh_lab::Degree seventh_lab::operator ""_Fahrenheit(const unsigned long long value)
{
	return Degree((static_cast<double>(value) - 32) / 1.8);
}
