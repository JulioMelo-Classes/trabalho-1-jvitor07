#include "Validator.hpp"

void Validator::checkFileExistence(std::ifstream &file)
{
    if(!file.good()) throw "Deu beyblade";
}

void Validator::checkNumbersAmount(std::vector<int> numbers)
{
    int amount = numbers.size();

    if(amount < 0 || amount > 14) throw "Quantidade de números invalida";
}