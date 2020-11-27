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
// Takes filename string by reference and returns output via input string.
// Returns false if the filename contains a space or 
//  does not have a '.' separating the name and extension.
// Returns true otherwise
//
// Preconditions : 
//     filename must be a valid lvalue std::string
// Exception Guaruntee :
//     Strong guaruntee - uses commit/roll back
bool getFileName(std::string& filename)
{
    // use this string to ensure strong guaruntee
    std::string tempString;

    // prompt user and collect input
    std::cout << "Please enter the name of the file you would like to read from: ";
    std::getline(std::cin, tempString);
    
    // We want to check that what has been entered is a valid filename.
    // since this varies from system to system, we will only have two requirements
    bool hasPeriod = false;
    for(std::size_t i = 0; i < tempString.size(); ++i)
    {
        // if filename contains a space, the input is invalid, so we return false
        if(tempString[i] == ' ')
        {
            return false;
        }
        // filename must contain a '.' to separate the name from the extension,
        // and as such it must not be the first or last character in the file name
        else if(tempString[i] == '.' && i != 0 && i != tempString.size() - 1)
        {
            hasPeriod = true;
        }
    }

    // commit changes
    filename = tempString;

    // return whether the filename is passably valid
    return hasPeriod;
}



// printErr function
//
// Prints an error message
// Takes no parameters and returns void
//
// Preconditions : none
// Exception Guaruntee : 
//     Strong Guaruntee - no data to modify
void printErr()
{
    std::cout << "\nSomething went wrong!\n"
              << "Please check that the file exists and that you have entered the name correctly.\n"
              << "Please Try again!\n\n";
}



// readFile function
//
// Takes an ifstream and a map<string, int>, both by reference.
// Reads through the file, storing each distinct word in the map, and updating the number of times
//  that the word appears in the file.
// Returns void
//
// Preconditions : 
//     Both parameters must be valid lvalues of their respective types.
//     Words should be empty and inFile should be at the beginning of the file if the
//      client code wishes to read the entire file and for words to only reflect that file's data.
// Exception Guaruntee :
//     Basic Guaruntee - function must constantly modify inFile and words throughout
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
// Takes a map<string, int> by reference.
// Tells the user how many words were stored in the map, then displays each alongside the
//  number of times that they appeared.
//
// Preconditions :
//     words must be a valid lvalue map<string, int>
// Exception Guaruntee :
//     Strong Guaruntee - data is never modified
void printResults(const std::map<std::string, int>& words)
{
    // print distinct word count
    std::cout << "There are " << words.size() << " distinct words in the file.\n\n";

    // print each word and its frequency
    for(auto m : words)
    {
        std::cout << m.first << ": " << m.second << std::endl;
    }
}


// main function
//
// (Do I need to write all the normal comments for function main? I will just to be safe)
// Gets a filename from the user, reads the file, and prints some information about it for the user
//
// Preconditions : 
//     none
// Exception Guaruntee :
//     Strong guaruntee - all data is internal, file read is never modified
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

        // open the filestream, check for errors
        std::ifstream inFile(filename);
        if(!inFile) ERROR

        // read in the words
        readFile(inFile, words);

        // check if it stopped before reaching eof
        if(!inFile.eof()) ERROR

        // spit out the results
        printResults(words);

        // reset for the next file
        words.clear();
    }

    return 0;
}