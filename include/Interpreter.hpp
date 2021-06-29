#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <fstream>
#include <vector>
#include <string>

#include "Validator.hpp"


class Interpreter : public Validator
{
    public: std::string filePath;
    std::ifstream file;
    std::vector<std::string> text;
    std::vector<int> numbers;

    Interpreter(std::string filePath);

    public: void openFile();
     void closeFile();
     void setText();
     std::vector<std::string> getText();
     void setNumbers();
     std::vector<int> getNumbers();
};

#endif