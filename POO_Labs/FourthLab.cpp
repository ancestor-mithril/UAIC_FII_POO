#include "FourthLab.h"

#include <iostream>
#include <sstream>

void forth_lab::Sort::quickSort(const int low, const int high)
{
	if (low < high)
	{
		const auto pivot = partition(low, high);
		quickSort(low, pivot - 1);
		quickSort(pivot + 1, high);
	}
}

int forth_lab::Sort::partition(const int low, const int high)
{
	const int pivotIndex = rand() % (high - low + 1) + low;
	std::swap(_data[pivotIndex], _data[high]);
	const auto pivot = _data[high];
	int i = low - 1;
	for (int j = low; j < high; ++j)
	{
		if (_data[j] <= pivot)
		{
			i++;
			std::swap(_data[i], _data[j]);
		}
	}
	std::swap(_data[i + 1], _data[high]);
	return i + 1;
}

forth_lab::Sort::Sort(const int count, const int min, const int max)
{
	for (auto i = 0; i < count; ++i)
	{
		_data.push_back(rand() % max + min);
	}
}

forth_lab::Sort::Sort(std::vector<int> data) : _data(std::move(data))
{
}


forth_lab::Sort::Sort(int* vector, const int count)
{
	//std::vector<int> vec(vector, vector + count);
	//_data = std::move(vec);

	//std::copy_n(vector, count, std::back_inserter(_data));
	//std::copy_n(vector, count, _data); // ERROR

	_data.insert(_data.end(), &vector[0], &vector[count]);
}

forth_lab::Sort::Sort(const std::initializer_list<int> data) : _data(data)
{
}


forth_lab::Sort::Sort(std::string& data)
{
	std::stringstream dataTokenizer(data);
	
	for (int i; dataTokenizer >> i;)
	{
		_data.push_back(i);
		if (dataTokenizer.peek() == ',')
		{
			dataTokenizer.ignore();
		}
	}
}

void forth_lab::Sort::InsertSort(const bool ascendent) //select sort
{
	const auto n = _data.size();
	
	for (unsigned int i = 0; i < n - 1; ++i)
	{
		for (unsigned int j = i + 1; j < n; ++j)
		{
			if (_data[i] < _data[j] == ascendent)
			{
				std::swap(_data[i], _data[j]);
			}
		}
	}
}

void forth_lab::Sort::QuickSort(bool ascendent)
{
	quickSort(0, _data.size() - 1);
	//TODO: use ascendent
}

void forth_lab::Sort::BubbleSort(bool ascendent)
{
	const int n = _data.size();
	
	/*auto swapped = true;
	while (swapped)
	{
		swapped = false;
		for (int i = 1; i < n; ++i)
		{
			if (_data[i - 1] > _data[i])
			{
				std::swap(_data[i - 1], _data[i]);
				swapped = true;
			}
		}
	}*/
	
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (_data[j] > _data[j + 1])
			{
				std::swap(_data[j], _data[j + 1]);
			}
		}
	}
	//TODO: use ascendent
}

void forth_lab::Sort::Print()
{
	for (auto i = _data.begin(); i != _data.end(); ++i)
	{
		std::cout << *i << ' ';
	}
	std::cout << std::endl;
}

int forth_lab::Sort::GetElementsCount() const
{
	return _data.size();
}

int forth_lab::Sort::GetElementFromIndex(const int index)
{
	if (index < 0 || index >= _data.size())
	{
		throw std::out_of_range("Invalid index");
	}
	
	return _data[index];
}


