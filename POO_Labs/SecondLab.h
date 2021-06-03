#pragma once
#include <string>

namespace second_lab
{
	class NumberList
	{
		int numbers[10];
		int count;
	public:
		void Init();          // count will be 0
		bool Add(int x);      // adds X to the numbers list and increase the data member count.
					  // if count is bigger or equal to 10, the function will return false
		void Sort();          // will sort the numbers vector
		void Print();         // will print the current vector
	};

	class Student
	{
		std::string _name;
		float _mathGrade;
		float _englishGrade;
		float _historyGrade;
	public:
		Student();
		explicit Student(std::string name);
		Student(const Student& other) = default;
		Student(Student&& other) = default;
		Student& operator=(const Student& other) = default;
		Student& operator=(Student&& other) = default;
		~Student() = default;
		
		float MathGrade() const;
		float EnglishGrade() const;
		float HistoryGrade() const;
		std::string Name() const;

		void SetName(const std::string& name);
		void SetMathGrade(float mathGrade);
		void SetEnglishGrade(float englishGrade);
		void SetHistoryGrade(float historyGrade);
		float AverageGrade() const;

		friend int compareName(const Student&, const Student&);
		friend int compareMathGrade(const Student&, const Student&);
		friend int compareEnglishGrade(const Student&, const Student&);
		friend int compareHistoryGrade(const Student&, const Student&);
		friend int compareAverageGrade(const Student&, const Student&);
	};
}

