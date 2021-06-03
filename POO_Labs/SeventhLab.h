#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "CustomException.h"

namespace seventh_lab
{
	class Degree
	{
		double _value = 0;
	public:
		Degree() = default;
		explicit Degree(double value);
		Degree(const Degree& other) = default;
		Degree(Degree&& other) = default;
		Degree& operator=(const Degree& other) = default;
		Degree& operator=(Degree&& other) = default;
		~Degree() = default;

		explicit operator float() const;

	};
	Degree operator"" _Kelvin(unsigned long long value);
	Degree operator"" _Fahrenheit(unsigned long long value);

	template <class T>
	class TemplateVector
	{
		std::vector<T> _container;
	public:
		void Push(T element);
		T Pop();
		void Delete(int index);
		void Insert(T element, int index);
		void Sort(bool (*comparisonFunction)(T& e1, T& e2) = nullptr);
		const T& Get(int index);
		void Set(T element, int index);
		int Count();
		int FirstIndexOf(T element, bool (*callbackFunction)(T& e) = nullptr);
		void Print();
	};

	template <class T>
	void TemplateVector<T>::Push(T element)
	{
		_container.emplace_back(element);
	}

	template <class T>
	T TemplateVector<T>::Pop()
	{
		if (_container.empty())
		{
			throw utils::CustomException("Container is empty");
		}

		return _container.back();
	}

	template <class T>
	void TemplateVector<T>::Delete(int index)
	{
		if (index < 0 || index >= _container.size())
		{
			throw std::out_of_range(std::to_string(index) + " is not in range");
		}

		_container.erase(_container.begin() + index);
	}

	template <class T>
	void TemplateVector<T>::Insert(T element, int index)
	{
		if (index < 0 || index > _container.size())
		{
			throw std::out_of_range(std::to_string(index) + " is not in range");
		}

		if (index == _container.size())
		{
			_container.push_back(element);
		}
		else
		{
			_container.insert(_container.begin() + index, element);
		}
	}

	template <class T>
	void TemplateVector<T>::Sort(bool(*comparisonFunction)(T& e1, T& e2))
	{
		if (comparisonFunction == nullptr)
		{
			comparisonFunction = [](T& e1, T& e2) -> bool
			{
				return static_cast<bool>(e1 < e2);
			};
		}
		std::sort(_container.begin(), _container.end(), comparisonFunction);
	}

	template <class T>
	const T& TemplateVector<T>::Get(int index)
	{
		if (index < 0 || index >= _container.size())
		{
			throw std::out_of_range(std::to_string(index) + " is not in range");
		}

		return _container[index];
	}

	template <class T>
	void TemplateVector<T>::Set(T element, int index)
	{
		if (index < 0 || index >= _container.size())
		{
			throw std::out_of_range(std::to_string(index) + " is not in range");
		}

		_container[index] = element;
	}

	template <class T>
	int TemplateVector<T>::Count()
	{
		return _container.size();
	}

	template <class T>
	int TemplateVector<T>::FirstIndexOf(T element, bool(*callbackFunction)(T& e))
	{
		auto begin = _container.begin();

		if (callbackFunction == nullptr)
		{
			auto lambda = [&](T& e) -> bool
			{
				return e == element;
			};
			auto iterator = std::find_if(_container.begin(), _container.end(), lambda);
			return iterator - begin;
		}

		auto iterator = std::find_if(_container.begin(), _container.end(), callbackFunction);
		return iterator - begin;
	}

	template <class T>
	void TemplateVector<T>::Print()
	{
		std::cout << "Printing vector: " << "\n";

		for (auto& e : _container)
		{
			std::cout << e << ", ";
		}

		std::cout << '\n';
	}
}

