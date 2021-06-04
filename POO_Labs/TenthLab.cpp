#include "TenthLab.h"

#include <algorithm>
#include <iostream>
#include <vector>

tenth_lab::TenthLab::TenthLab() : TenthLab({ "da", "nu", "doi", "trey", "unu" })
{
}

tenth_lab::TenthLab::TenthLab(std::vector<std::string> strings) : _strings(std::move(strings)) {
}

void tenth_lab::TenthLab::Sort()
{
	std::sort(_strings.begin(), _strings.end(), [](std::string& str1, std::string& str2) -> bool
		{
			return str2.size() == str1.size() ? str1 <= str2 : str2.size() > str1.size();
		}
	);
}

std::function<int(std::vector<int>&)> tenth_lab::TenthLab::CreateLambda() const
{
	return [](std::vector<int>& vector) -> int
	{
		return vector[std::max(vector.begin(), vector.end()) - vector.begin()];
	};
}

void tenth_lab::TenthLab::Print()
{
	std::cout << "Printing vector: " << "\n";

	for (auto& value : _strings)
	{
		std::cout << value << '\n';
	}
	
	std::cout << "\n";
}

bool tenth_lab::MyVector::Add(const int x)
{
	_vector.push_back(x);
	return x;
}

bool tenth_lab::MyVector::Delete(const int index)
{
	if (index < 0 || index >= _vector.size())
	{
		return false;
	}
	
	_vector.erase(_vector.begin() + index);
	return true;
}

void tenth_lab::MyVector::Iterate(std::function<void(int&)>& lambda)
{
	for (auto& value : _vector)
	{
		lambda(value);
	}
}

void tenth_lab::MyVector::Filter(std::function<bool(int&)>& lambda)
{
	for (auto it = _vector.begin(); it != _vector.end(); )
	{
		if (lambda(*it))
		{
			_vector.erase(it);
		}
		++it;
	}
}

void tenth_lab::MyVector::Print()
{
	std::cout << "Printing vector: " << "\n";

	for (auto& value : _vector)
	{
		std::cout << value << '\n';
	}
	std::cout << "\n";
}
