#include <iostream>
#include <boost/tokenizer.hpp>
#include "include/InvertedIndex.h"

using namespace std;
using namespace boost;
int main(){
    InvertedIndex invertedIndex1;
    invertedIndex1.getPath();
    invertedIndex1.printExerciseOne();
    invertedIndex1.printExerciseTwo();
}