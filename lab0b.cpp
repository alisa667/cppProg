#include <iostream>
#include "WordCounter.h"

int main()
{
    std::string fileInName;
    std::string fileOutName;
    std::cout << "Enter name of the input file...";
    std::cin >> fileInName;
    std::cout << "Enter name of the output file...";
    std::cin >> fileOutName;
    WordCounter obj(fileInName, fileOutName);
}

