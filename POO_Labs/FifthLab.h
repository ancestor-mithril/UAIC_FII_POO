#pragma once
#include <string>

namespace fifth_lab
{
	class Number
	{
		bool _negative = false;
		std::string _value;
		int _base;
	public:
		Number(const char* value, int base); // where base is between 2 and 16
		Number(const Number& other) = default;
		Number(int);
		Number(Number&& other) = default;
		Number& operator=(const Number& other) = default;
		Number& operator=(Number&& other) = default;
		Number& operator=(int);
		Number& operator=(const char*);
		~Number() = default;

		void SwitchBase(int newBase);
		void Print() const;
		int  GetDigitsCount() const; // returns the number of digits for the current number
		int  GetBase() const; // returns the current base
		void Negate();

		bool operator! () const;
		Number operator- () const;
		char operator[] (int) const;
		Number& operator--();
		Number& operator--(int);
		Number& operator+=(Number&);

		friend Number operator+(const Number&, const Number&);
		friend Number operator-(const Number&, const Number&);
		friend bool operator>(const Number&, const Number&);
		friend bool operator<(const Number&, const Number&);
		friend bool operator>=(const Number&, const Number&);
		friend bool operator<=(const Number&, const Number&);
		friend bool operator==(const Number&, const Number&);
		friend bool operator!=(const Number&, const Number&);
	};
}
