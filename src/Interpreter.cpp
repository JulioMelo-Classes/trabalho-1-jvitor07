#include "Interpreter.hpp"

Interpreter::Interpreter(std::string filePath)
{
    this->filePath = filePath;
}

void Interpreter::openFile()
{
    this->file.open(this->filePath);
    this->checkFileExistence(this->file);
}

void Interpreter::closeFile()
{
    this->file.close();
}

void Interpreter::setText()
{
    while(!this->file.eof())
    {
        std::string line;
        getline(this->file, line);
        this->text.push_back(line);
    }

    this->closeFile();
}

std::vector<std::string> Interpreter::getText()
{
    return this->text;
}

void Interpreter::setNumbers()
{
    std::string strNumbers = this->text.at(2);
    std::stringstream check(strNumbers);
    std::string token;

    while(getline(check, token, ' '))
    {
        this->checkStrangeCharacter(token);
        this->numbers.push_back(std::stoi(token));
    }
    

    this->checkNumbersAmount(this->numbers);
    this->checkNumbersRepetition(this->numbers);
}

std::vector<int>Interpreter::getNumbers()
{
    return this->numbers;
}