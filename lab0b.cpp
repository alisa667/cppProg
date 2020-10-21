#include <iostream>
#include "WordCounter.h"

int main()
{
    std::string fileInName;
    std::string fileOutName;
    std::cout << "Enter name of the input file...";
    std::cin >> fileInName;
    WordCounter counter;
    try {
        counter.readWords(fileInName);
    }
    catch (std::logic_error& e) {
        std::cerr << e.what();
        return 0;
    };
    std::cout << "Enter name of the output file...";
    std::cin >> fileOutName;
    try {
        counter.writeWords(fileOutName);
    }
    catch (std::logic_error& e) {
        std::cerr << e.what();
        return 0;
    };
}


