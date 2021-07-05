#include "Validator.hpp"

/*! 
 * @param file Referencia para a variavel do arquivo
 * @throw Uma exceção no formato de string com a mensagem "Arquivo inexistente"
 * @return void
 */
void Validator::checkFileExistence(std::ifstream &file)
{
    if(!file.good()) throw "Arquivo inexistente";
}

/*! 
 * @param numbers vetor de números inteiros que o usuário escolheu
 * @throw Uma exceção no formato de string com a mensagem "Quantidade de números invalida",
 * caso o jogador não escolha números ou escolha mais que o máximo permitido
 * @return void
 */
void Validator::checkNumbersAmount(std::vector<int> numbers)
{
    int amount = numbers.size();

    if(amount < 1 || amount > 15) throw "Quantidade de números invalida";
}

/*! 
 * @param numbers vetor de números inteiros que o usuário escolheu
 * @throw Uma exceção no formato de string com a mensagem "Houve repetição de números",
 * caso ocorra repetição nos números escolhidos pelo jogador.
 * @return void
 */
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

/*! 
 * @param token Uma string que pretende ser convertida para um número inteiro
 * @throw Uma exceção no formato de string com a mensagem "Insira um número inteiro",
 * caso o jogador insira um valor inválido
 * @return void
 */
void Validator::checkIntegerNumber(std::string token)
{
    try{
        std::stoi(token);
    }catch(std::invalid_argument ia){
        throw "Insira um número inteiro";
    }
}

/*! 
 * @param token Uma string que pretende ser convertida para um número real
 * @throw Uma exceção no formato de string com a mensagem "Insira um número real",
 * caso o jogador insira um valor inválido
 * @return void
 */
void Validator::checkRealNumber(std::string token)
{
    std::size_t cmp = token.find(".");
    if(cmp == std::string::npos) throw "Insira um número real";
}

/*! 
 * @param token Uma string que pretende ser convertida para um número inteiro
 * @param valor mínimo do range
 * @param valor máximo do range
 * @throw Uma exceção no formato de string com a mensagem "Número inválido",
 * caso o jogador insira um valor inválido
 * @return void
 */
void Validator::checkNumberInterval(std::string token, int min, int max)
{
    int value = std::stoi(token);
    if(value > max || value < min) throw "Número inválido";
}

/*! 
 * @param token Uma string que pretende ser convertida para um número
 * @throw Uma exceção no formato de string com a mensagem "Escreva apenas um número",
 * caso o jogador insira mais de um valor na linha
 * @return void
 */
void Validator::checkUniqueNumber(std::string token)
{
    std::size_t cmp = token.find(" ");
    if(cmp != std::string::npos) throw "Escreva apenas um número";
}