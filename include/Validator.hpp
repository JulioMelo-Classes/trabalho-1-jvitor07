#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <fstream>
#include <vector>
#include <string>

/*! 
 * Classe que responsável pelos metodos de validação
 */
class Validator
{
    protected: void checkFileExistence(std::ifstream &file); 
     void checkNumbersAmount(std::vector<int> numbers);
     void checkNumbersRepetition(std::vector<int> numbers);
     void checkIntegerNumber(std::string token);
     void checkRealNumber(std::string token);
     void checkNumberInterval(std::string token, int min, int max);
     void checkUniqueNumber(std::string token);
};

#endif