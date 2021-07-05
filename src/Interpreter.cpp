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

/*! 
 * Abre um arquivo e valida a sua existência
 * @return void
 */
void Interpreter::openFile()
{
    this->file.open(this->filePath);
    this->checkFileExistence(this->file);
}

/*! 
 * Fecha um arquivo
 * @return void
 */
void Interpreter::closeFile()
{
    this->file.close();
}

/*! 
 * Copia o texto que está no arquivo para um vetor
 * @return void
 */
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

/*! 
 * Retorna o vetor com o texto do arquivo de entrada
 * @return this->text texto contido no arquivo de entrada
 */
std::vector<std::string> Interpreter::getText()
{
    return this->text;
}

/*! 
 * Valida o dinheiro no arquivo de entrada e atribui seu valor a variavel this->money
 * @return void
 */
void Interpreter::setMoney()
{
    std::string strMoney = this->text.at(0);
    this->checkUniqueNumber(strMoney);
    this->checkRealNumber(strMoney);
    this->money = std::stod(strMoney);
}

/*! 
 * Retorna o valor atual do dinheiro do jogador
 * @return this->money dinheiro do jogador
 */
double Interpreter::getMoney()
{
    return this->money;
}

/*! 
 * Valida os rounds no arquivo de entrada e atribui o valor para a variavel this->round
 * @return void
 */
void Interpreter::setRounds()
{
    std::string strRounds = this->text.at(1);
    this->checkUniqueNumber(strRounds);
    this->checkIntegerNumber(strRounds);
    this->rounds = std::stoi(strRounds);
}

/*! 
 * Retorna o o total de rounds
 * @return this->rounds o total dos rounds da aposta
 */
int Interpreter::getRounds()
{
    return this->rounds;
}

/*! 
 * Valida os números e atribui os valores para o vetor this->numbers
 * @return void
 */
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

/*! 
 * Retorna o vetor com os números da aposta do jogador
 * @return this->numbers número da aposta
 */
std::vector<int>Interpreter::getNumbers()
{
    return this->numbers;
}