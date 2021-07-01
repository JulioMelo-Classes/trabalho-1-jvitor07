#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

#include "Interpreter.hpp"
#include "KenoBet.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    try{
        std::cout << ">>> Lendo arquivos de apostas [" << argv[1] << "], por favor aguarde..." << std::endl;

        Interpreter *interpreter = new Interpreter(argv[1]);
        KenoBet *keno = new KenoBet();

        keno->set_wage(interpreter->getMoney());
        keno->set_rounds(interpreter->getRounds());
        keno->set_m_spots(interpreter->getNumbers());

        keno->play();
        
    }catch(const char *msg) {
        std::cerr << "\033[31m>>> Aconteceu um erro: "<< msg << std::endl;
    }

    return 0;
}