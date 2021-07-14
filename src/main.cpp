#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

#include "Interpreter.hpp"
#include "KenoBet.hpp"

using namespace std;

/*
Avaliação
Processamento do Arquivo de Entrada: 1
Execução correta: 1
Interfcace Textual: 1
Documentação: 1
Compilação automatizada: 1
Organização em src, include, build, data: 1

Comentários
- A indentação nos .h ficou, no mínimo, estranha. Acredito que conversei isso com vocês na entrevista
usualmente a indentação das classes é como eu coloquei na classe Interpreter.hpp. Outro ponto que vocês podem
verificar é o uso de atributos publicos com get/set. Usualmente, gets/sets só tem sentido em atributos privados.
- No geral acho que ficou muito boa a organização e o próprio uso de orientação à objetos de forma simples, creio
que o segundo trabalho não vá ser problema pra vcs. Talvez apenas o melhor uso dos atributos para evitar classes
como as classe Teller e Validator. 
- Quando usamos uma classe apenas para termos de organização, usamos métodos estáticos, assim não é necessário
instanciar um objeto apeans para chamar métodos que não operam em qualquer atributo. No entanto, acho que não se
aplica ao caso de vcs. Talvez a classe Teller pudesse usar uma referencia ou mesmo uma cópia do objeto kenobet,
assim ela não precisa ter funções que recebem tantos parâmetros. A classe validator, poderia cuidar 100% da abertura
e processamento do arquivo, se guardasse o arquivo como atributo, ao invés de receber tudo por parâmetro no método.
*/

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