#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

#include "Validator.hpp"


class Interpreter : public Validator
{
    public: std::string filePath;
    std::ifstream file;
    std::vector<std::string> text;
    double money;
    int rounds;
    std::vector<int> numbers;

    Interpreter(std::string filePath);

    public: void openFile();
     void closeFile();
     void setText();
     std::vector<std::string> getText();
     void setMoney();
     double getMoney();
     void setRounds();
     int getRounds();
     void setNumbers();
     std::vector<int> getNumbers();
};

#endif