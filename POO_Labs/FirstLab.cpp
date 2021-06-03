#include "FirstLab.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

#include "CustomException.h"


first_lab::FirstExercise::FirstExercise(const std::string& filePath)
{
	std::ifstream targetFile(filePath);
	if (!targetFile.is_open()) {
		std::ostringstream errorMessage;
		errorMessage << "File " << filePath << " couldn't be opened";
		throw utils::CustomException(errorMessage.str());
	}
	int numberOnLine;
	while (targetFile >> numberOnLine) {
		_sum += numberOnLine;
	}
}


int first_lab::FirstExercise::GetSum() const
{
	return _sum;
}

first_lab::SecondExercise::SecondExercise(const std::string& filePath)
{
	std::ifstream targetFile(filePath);
	std::string sentence;
	std::getline(targetFile, sentence);
	std::istringstream wordTokenizer(sentence);
	std::string word;
	while (wordTokenizer >> word) {
		_words.push_back(word);
	}
	std::sort(_words.begin(), _words.end(), [](const std::string& word1, const std::string& word2){
			return !(word1.size() == word2.size() ? word1 < word2 : word1.size() < word2.size());
		}
	);
}

std::vector<std::string> first_lab::SecondExercise::GetWords() const
{
	return _words;
}
