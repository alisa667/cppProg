#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include <string>

class WordCounter {
public:
	void readWords(const std::string& fileInName ) {
		std::string word;
		std::ifstream fileIn;
		fileIn.open(fileInName);
		if (!fileIn) {
			throw std::logic_error("Unable to open input file");

		}
		while (std::getline(fileIn, word, ' ')) {
			std::string new_word = "";
			for (unsigned int i = 0; i < word.size(); i++) {
				if ((word[i] >= 48 && word[i] <= 57) || (word[i] >= 97 && word[i] <= 122))
					new_word += word[i];
				else if (new_word != ""){
					words[new_word]++;
					new_word = "";
				}
			}
			if (new_word != "")
				words[new_word]++;
		}
	}

	void writeWords(const std::string& fileOutName) {
		std::ofstream fileOut;
		fileOut.open(fileOutName);
		if (!fileOut) {
			throw std::logic_error("Unable to open output file");
		}
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
private:
	std::map <std::string, int> words;
	struct WordFreq {
		std::string word;
		int freq;
		WordFreq() {
			freq = 0;
		}
	};
	
};
