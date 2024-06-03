#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void appendToFile(const std::string &filename, const std::string &data) {
    std::ofstream outfile;
    outfile.open(filename, std::ios_base::app); // Append mode
    if (outfile.is_open()) {
        outfile << data << std::endl;
        outfile.close();
    } else {
        std::cerr << "Unable to open file for appending." << std::endl;
    }
}

void reverseFileContent(const std::string &inputFilename, const std::string &outputFilename) {
    std::ifstream infile(inputFilename);
    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();
    
    std::reverse(content.begin(), content.end());
    
    std::ofstream outfile(outputFilename);
    if (outfile.is_open()) {
        outfile << content;
        outfile.close();
    } else {
        std::cerr << "Unable to open file for writing reversed content." << std::endl;
    }
}

int main() {
    std::string directory = "/Users/camdenbirkeland/Desktop/VSC - C++ Projects/Week 5 CT/";
    std::string filename = directory + "CSC450_CT5_mod5.txt";
    std::string reversedFilename = directory + "CSC450-mod5-reverse.txt";
    std::string userInput;
    
    std::cout << "Enter the text you want to append to the file: ";
    std::getline(std::cin, userInput);
    
    appendToFile(filename, userInput);
    reverseFileContent(filename, reversedFilename);
    
    std::cout << "Your input has been appended to the file and the reversed content has been written to " << reversedFilename << std::endl;
    
    return 0;
}