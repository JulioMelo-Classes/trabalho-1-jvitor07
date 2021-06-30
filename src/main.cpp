#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "Interpreter.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    try{
        std::cout << ">>> Lendo arquivos de apostas [" << argv[1] << "], por favor aguarde..." << std::endl;

        Interpreter *interpreter = new Interpreter(argv[1]);

        double money = interpreter->getMoney();
        int rounds = interpreter->getRounds();
        std::vector<int> numbers = interpreter->getNumbers();
        
        std::cout << ">>> Aposta lida com sucesso!" << std::endl;
        std::cout << "Você apostará um total de $" << money << " créditos." << std::endl;
        std::cout << "Jogará um total de " << rounds << " rodadas, apostando $" << money / rounds << " créditos por rodada" << std::endl;
        std::cout << "Sua aposta tem " << numbers.size() << " números, eles são: [ ";

        for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        {
            std::cout << *it << " ";
        }

        std::cout << "]" << std::endl;

    }catch(const char *msg) {
        std::cerr << "\033[31m>>> Aconteceu um erro: "<< msg << std::endl;
    }

    return 0;
}