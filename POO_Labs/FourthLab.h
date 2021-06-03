#pragma once
#include <vector>
#include <string>
namespace forth_lab
{
	class Sort
	{
		std::vector<int> _data;

		void quickSort(int low, int high);
		int partition(int low, int high);
	public:
		Sort(int count, int min, int max);
		explicit Sort(std::vector<int>);
		Sort(int* vector, int count);
		Sort(std::initializer_list<int>);
		explicit Sort(std::string&);

		Sort(const Sort& other) = default;
		Sort(Sort&& other) = default;
		Sort& operator=(const Sort& other) = default;
		Sort& operator=(Sort&& other) = default;
		~Sort() = default;

		void InsertSort(bool ascendent = false);
		void QuickSort(bool ascendent = false);
		void BubbleSort(bool ascendent = false);
		void Print();
		int  GetElementsCount() const;
		int  GetElementFromIndex(int index);
	};
}

