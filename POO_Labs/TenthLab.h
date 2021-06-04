#pragma once
#include <functional>
#include <string>
#include <vector>

namespace tenth_lab
{
	class TenthLab
	{
		std::vector<std::string> _strings;
	public:
		TenthLab();
		explicit TenthLab(std::vector<std::string> strings);
		void Sort();
		std::function<int(std::vector<int>&)> CreateLambda() const;
		void Print();
	};

	class MyVector {
		std::vector<int> _vector;
	public:
		bool Add(int); // return true if the value was added. As a result, the size of the vector increases with one.
		bool Delete(int index); // returns true if the value from the index was removed. As a result, the size of the vector decreases with one.
		void Iterate(std::function<void(int&)>& lambda);
		void Filter(std::function<bool(int&)>& lambda);
		void Print();
	};
}

