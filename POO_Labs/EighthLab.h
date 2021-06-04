#pragma once
#include <functional>
#include <map>
#include <queue>
#include <string>
#include <vector>

namespace eighth_lab
{
	class EighthLab
	{
		std::string _sentence;
		std::vector<std::string> _words;
		std::map<std::string, std::size_t> _wordCount;
		std::priority_queue<std::string, std::vector<std::string>, std::function<bool(std::string&, std::string&)>> _queue;
		static std::string stringToLower(const std::string& str);
	public:
		explicit EighthLab(const std::string& filePath = "./cin.txt");
		EighthLab(const EighthLab& other) = delete;
		EighthLab(EighthLab&& other) = delete;
		EighthLab& operator=(const EighthLab& other) = delete;
		EighthLab& operator=(EighthLab&& other) = delete;
		~EighthLab() = default;

		void TokenizeSentence();
		void PrintWords() const;
		void CountWords();
		void Sort();
		void PrintMap() const;
		void PrintSorted();

	};
}

