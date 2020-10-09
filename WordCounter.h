#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include <string>

class WordCounter {
public:
	WordCounter(std::string fileInName, std::string fileOutName) {
		fileIn.open(fileInName);
		fileOut.open(fileOutName);
		std::map <std::string, int> words = fillMap();
		sortList(words);
		
	}
	~WordCounter() {
		fileIn.close();
		fileOut.close();
	}
private:
	std::ofstream fileOut;
	std::ifstream fileIn;
	std::map <std::string, int> fillMap() {
		std::map <std::string, int> words;
		std::string word;
		while (std::getline(fileIn, word, ' '))
			words[word]++;
		return words;
	}

	struct WordFreq {
		std::string word;
		int freq;
		WordFreq() {
			freq = 0;
		}
	};

	void sortList(std::map <std::string, int> words) {
		std::list <WordFreq> wordsList;
		float freqSum = 0;
		for (auto it = words.begin(); it != words.end(); ++it) {
			WordFreq w;
			w.word = it->first;
			w.freq = it->second;
			freqSum += w.freq;
			wordsList.push_back(w);
		}
		wordsList.sort([](const WordFreq& first, const WordFreq& second) {return first.freq > second.freq; });
		for (auto itList = wordsList.begin(); itList != wordsList.end(); ++itList) {
			fileOut << itList->word << " " << itList->freq << " " << itList->freq / freqSum * 100 << std::endl;
		}
	}
};