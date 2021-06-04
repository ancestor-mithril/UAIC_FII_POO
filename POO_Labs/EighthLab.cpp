#include "EighthLab.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "CustomException.h"

std::string eighth_lab::EighthLab::stringToLower(const std::string& str)
{
	auto copy = str;
	std::for_each(copy.begin(), copy.end(), [](char& c)
		{
			c = static_cast<char>(toupper(c));
		}
	);
	return copy;
}

eighth_lab::EighthLab::EighthLab(const std::string& filePath)
{
	std::ifstream fin(filePath);

	if (!fin.is_open())
	{
		throw utils::CustomException("File " + filePath + " couldn't be opened");
	}

	std::getline(fin, _sentence);
}

void eighth_lab::EighthLab::TokenizeSentence()
{
	const std::string delimiters = " ,?!.";
	while (true)
	{
		const auto found = _sentence.find_first_of(delimiters);
		if (found != 0)
		{
			_words.push_back(_sentence.substr(0, found));
		}

		if (found == std::string::npos)
		{
			break;
		}

		_sentence.erase(0, found + 1);
	}
}

void eighth_lab::EighthLab::PrintWords() const
{
	std::cout << "Printing words: " << "\n";

	for (auto& word : _words)
	{
		std::cout << word << '\n';
	}
	std::cout << "\n";
}

void eighth_lab::EighthLab::CountWords()
{
	for (const auto& word : _words)
	{
		if (word.empty())
		{
			continue;
		}
		auto lowerCaseWord = stringToLower(word);
		const auto it = _wordCount.find(lowerCaseWord);
		if (it == _wordCount.end())
		{
			_wordCount.emplace(std::make_pair(lowerCaseWord, 1));
		}
		else
		{
			it->second++;
		}
	}
}

void eighth_lab::EighthLab::Sort()
{
	std::function<bool(std::string&, std::string&)> compare = [&](std::string& str1, std::string& str2) -> bool
	{
		const auto count1 = _wordCount.find(str1)->second;
		const auto count2 = _wordCount.find(str2)->second;
		return count1 == count2 ? str1 <= str2 : count1 <= count2;
	};

	std::priority_queue<std::string, std::vector<std::string>, decltype(compare)> queue(compare);
	for (auto& word : _wordCount)
	{
		queue.push(word.first);
	}

	_queue = std::move(queue);
}

void eighth_lab::EighthLab::PrintMap() const
{
	std::cout << "Printing map: " << "\n" << "{" << "\n";

	for (const auto& word : _wordCount)
	{
		std::cout << "\t\"" << word.first << "\" : " << word.second << '\n';
	}

	std::cout << "}" << '\n';
}

void eighth_lab::EighthLab::PrintSorted()
{
	auto queueCopy = _queue;

	std::cout << "Printing sorted map: " << "\n" << "{" << "\n";

	while (!queueCopy.empty())
	{
		auto word = queueCopy.top();
		queueCopy.pop();

		std::cout << "\t\"" << word << "\" : " << _wordCount.find(word)->second << '\n';
	}
	std::cout << "}" << '\n';
}



