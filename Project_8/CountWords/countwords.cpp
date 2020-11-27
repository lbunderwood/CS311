// Luke Underwood
// 11/26/2020 - Thanksgiving coding time!
// CS311
// Project 8
// CountWords
// countwords.cpp
// Complete program - takes a filename and counts the words in it, 
//  outputting them along with their number of appearances in alphabetical order


// STL Inclusions
#include <map>
    // For std::map
#include <fstream>
    // For std::ifstream
#include <string>
    // For std::string, std::getline
#include <iostream>
    // For std::cin, std::cout



// getFileName Function
//
bool getFileName(std::string& filename)
{
    
}

int main()
{
    // keys = words used, values = number of times the word has been used
    std::map<std::string, int> words;
    std::string filename = "";

    while(filename != "exit" && filename != "EXIT" && filename != "Exit")
    {
        getFileName(filename);
    }

    return 0;
}