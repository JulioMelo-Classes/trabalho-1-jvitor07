#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <fstream>
#include <vector>
#include <string>

class Validator
{
    protected: void checkFileExistence(std::ifstream &file); 
     void checkNumbersAmount(std::vector<int> numbers);
};

#endif