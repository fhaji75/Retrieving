
#include <bits/stdc++.h>
#pragma once
class InvertedIndex{
public:
    InvertedIndex();
    void getPath();
    void printExerciseOne();
    void printExerciseTwo();

private:
    void invertedIndex(int,std::string);
    std::string convertToString(int);
    int convertToInt(std::string);
    std::string inverse(std::string);
    std::map<std::string,std::vector<int>> inverted_Index;
    std::map<std::string,std::pair<std::string,int>>listOfDocument;
    std::string pathFile;
    std::string fileName;
    int helpVariable;
    std::string helpString;

};
