#pragma once
#include <string>
#include <iostream>
#include <vector>


namespace first_lab {
	class FirstExercise {
		int _sum = 0;
		void computeSum(std::ifstream& targetFile);
	public:
		explicit FirstExercise(const std::string& filePath = "./in.txt");
		FirstExercise(const FirstExercise& other) = delete;
		FirstExercise(FirstExercise&& other) = default;
		FirstExercise& operator=(const FirstExercise& other) = delete;
		FirstExercise& operator=(FirstExercise&& other) = delete;
		~FirstExercise() = default;
		int GetSum() const;
	};

	class SecondExercise {
		std::vector<std::string> _words;
	public:
		explicit SecondExercise(const std::string& filePath = "./cin.txt");
		SecondExercise(const SecondExercise& other) = default;
		SecondExercise(SecondExercise&& other) = default;
		SecondExercise& operator=(const SecondExercise& other) = default;
		SecondExercise& operator=(SecondExercise&& other) = default;
		~SecondExercise() = default;
		std::vector<std::string> GetWords() const;
	};
}


