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
#include <cstddef>
    // For std::size_t


// trying out using a macro because I've never used one and I repeat this 
// code a lot and want to condense it
#define ERROR {printErr(); continue;}



// getFileName Function
//
bool getFileName(std::string& filename)
{
    // prompt user, and collect input
    std::cout << "Please enter the name of the file you would like to read from: ";
    std::getline(std::cin, filename);
    
    // We want to check that what has been entered is a valid filename.
    // since this varies from system to system, we will only have two requirements
    bool hasPeriod = false;
    for(std::size_t i = 0; i < filename.size(); ++i)
    {
        // if filename contains a space, the input is invalid, so we return false
        if(filename[i] == ' ')
        {
            return false;
        }
        // filename must contain a '.' to separate the name from the extension,
        // and as such it must not be the first or last character in the file name
        else if(filename[i] == '.' && i != 0 && i != filename.size() - 1)
        {
            hasPeriod = true;
        }
    }

    // return whether the filename is passably valid
    return hasPeriod;
}

// printErr function
//
void printErr()
{
    std::cout << "Something went wrong!\n"
              << "Please check that the file exists and that you have entered the name correctly.\n"
              << "Please Try again!\n";
}

// readFile function
//
void readFile(std::ifstream& inFile, std::map<std::string, int>& words)
{
    // keep grabbing new words until it fails to do so
    std::string word;
    while(inFile >> word)
    {
        // try to insert the word
        auto insertResult = words.insert({word, 1});

        // if the word already existed
        if(!insertResult.second)
        {
            // iterate the word count
            ++(*insertResult.first).second;
        }
    }
}

// printResults function
//
void printResults(const std::map<std::string, int>& words)
{
    for(auto m : words)
    {
        std::cout << m.first << ": " << m.second << std::endl;
    }
}


int main()
{
    // keys = words used, values = number of times the word has been used
    std::map<std::string, int> words;
    std::string filename = "";

    // if the user types one of these things, we exit the loop and close the program
    while(filename != "exit" && filename != "EXIT" && filename != "Exit")
    {
        // get the input, display an error message and try again if it fails
        if(!getFileName(filename)) ERROR

        // open the filestream, display an error message and try again if it fails
        std::ifstream inFile(filename);
        if(!inFile) ERROR

        readFile(inFile, words);

        if(!inFile.eof()) ERROR

        printResults(words);
    }

    return 0;
}