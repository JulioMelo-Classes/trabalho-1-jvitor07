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

void Validator::checkStrangeCharacter(std::string token)
{
    try{
        int value = std::stoi(token);
        if(value > 80 || value < 1) throw "Número inválido";
    }catch(std::invalid_argument ia){
        throw "Caracter inválido";
    }
}