#include "Validator.hpp"

void Validator::checkFileExistence(std::ifstream &file)
{
    if(!file.good()) throw "Arquivo inexistente";
}

void Validator::checkNumbersAmount(std::vector<int> numbers)
{
    int amount = numbers.size();

    if(amount < 1 || amount > 15) throw "Quantidade de números invalida";
}

void Validator::checkNumbersRepetition(std::vector<int> numbers)
{
    int amount = numbers.size();
    bool repeat = false;

    for(std::vector<int>::iterator itOne = numbers.begin(); itOne != numbers.end(); itOne++)
    {
        for(std::vector<int>::iterator itTwo = numbers.begin(); itTwo != numbers.end(); itTwo++)
        {
            if(distance(itOne, itTwo) != 0 && *itOne == *itTwo) repeat = true;     
        }
    }

    if(repeat == true) throw "Houve repetição de números";
}

void Validator::checkIntegerNumber(std::string token)
{
    try{
        std::stoi(token);
    }catch(std::invalid_argument ia){
        throw "Insira um número inteiro";
    }
}

void Validator::checkRealNumber(std::string token)
{
    std::size_t cmp = token.find(".");
    if(cmp == std::string::npos) throw "Insira um número real";
}

void Validator::checkNumberInterval(std::string token, int min, int max)
{
    int value = std::stoi(token);
    if(value > max || value < min) throw "Número inválido";
}

void Validator::checkUniqueNumber(std::string token)
{
    std::size_t cmp = token.find(" ");
    if(cmp != std::string::npos) throw "Escreva apenas um número";
}