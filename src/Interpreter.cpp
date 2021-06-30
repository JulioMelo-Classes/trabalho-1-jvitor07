#include "Interpreter.hpp"

Interpreter::Interpreter(std::string filePath)
{
    this->filePath = filePath;
    this->openFile();
    this->setText();
    this->setMoney();
    this->setRounds();
    this->setNumbers();
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

void Interpreter::setMoney()
{
    std::string strMoney = this->text.at(0);
    this->checkUniqueNumber(strMoney);
    this->checkRealNumber(strMoney);
    this->money = std::stod(strMoney);
}

double Interpreter::getMoney()
{
    return this->money;
}

void Interpreter::setRounds()
{
    std::string strRounds = this->text.at(1);
    this->checkUniqueNumber(strRounds);
    this->checkIntegerNumber(strRounds);
    this->rounds = std::stoi(strRounds);
}

int Interpreter::getRounds()
{
    return this->rounds;
}

void Interpreter::setNumbers()
{
    std::string strNumbers = this->text.at(2);
    std::stringstream check(strNumbers);
    std::string token;

    while(getline(check, token, ' '))
    {
        this->checkIntegerNumber(token);
        this->numbers.push_back(std::stoi(token));
    }
    

    this->checkNumbersAmount(this->numbers);
    this->checkNumbersRepetition(this->numbers);
}

std::vector<int>Interpreter::getNumbers()
{
    return this->numbers;
}