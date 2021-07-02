#include "Teller.hpp"

void Teller::printHeader(int rounds, double totalWage, double roundWage)
{
    std::cout << ">>> Aposta lida com sucesso!" << std::endl;
    std::cout << "--------------------------------------------------------------------" << std::endl;
    std::cout << "Você apostará um total de $" << totalWage << " créditos." << std::endl;
    std::cout << "Jogará um total de " << rounds << " rodadas, apostando $" << roundWage << " créditos por rodada" << std::endl << std::endl;
}

void Teller::printTable(std::vector<int> numbers, std::vector<double> tableLine)
{
    std::cout << "Sua aposta tem " << numbers.size() << " números, eles são: [ ";

    for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << "]" << std::endl;

    std::cout << "----------+-----------" << std::endl;
    std::cout << "Hits      | Retorno" << std::endl;

    int counter = 0;
    for(std::vector<double>::iterator it = tableLine.begin(); it != tableLine.end(); it++)
    {
        std::cout << counter << "         | " << *it << std::endl;
        counter++;
    }
    
    std::cout << std::endl <<"------------------------------------------------------------" << std::endl;
}

void Teller::printRound(double money, int currentRound, int roundTotal, std::vector<int> drawNumbers)
{
    std::cout << "Esta é a rodada #" << currentRound << " de " << roundTotal << ", sua aposta é $" << money << ". Boa sorte!" << std::endl;
    std::cout << "Os números sorteados são: [ ";

    for(std::vector<int>::iterator it = drawNumbers.begin(); it != drawNumbers.end(); it++){
        std::cout << *it << " ";
    }
    
    std::cout << "]" << std::endl;
}

void Teller::printRoundResult(std::vector<int> hits, int hitQuantity, int numbersTotal, double multiplier, double result, double total)
{
    
    std::cout << "Você acertou os números [ "; 
    for(std::vector<int>::iterator it = hits.begin(); it != hits.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "], um total de " << hitQuantity << " hits de " << numbersTotal << std::endl;
    std::cout << "Sua taxa de retorno é " << multiplier << ", assim você sai com: $" << result << std::endl; 
    std::cout << "Você possui um total de: $" << total << " créditos." << std::endl;
    std::cout << " ------------------------------------------------------------" << std::endl;
}

void Teller::printSumary(double initialMoney, double finalMoney)
{
    std::cout << ">>> Fim das rodadas!" << std::endl << std::endl;
    std::cout << "======= Sumário =======" << std::endl;
    std::cout << ">>> Você gastou um total de $" << initialMoney << " créditos" << std::endl;
    if((finalMoney - initialMoney) > 0)
    {
        std::cout << ">>> Hooray! você ganhou $" << finalMoney - initialMoney << " créditos!" << std::endl;
    }
    else if((finalMoney - initialMoney) < 0){
        std::cout << ">>> Que pena, você perdeu $" << initialMoney - finalMoney << " créditos! Mais sorte na próxima vez. :P" << std::endl;
    }
    else if(finalMoney == 0){
        std::cout << ">>> Que pena, você perdeu tudo, Que azarado ^^." << std::endl;
    }
    else if(finalMoney == initialMoney){
        std::cout << ">>> Deu na merma! ¯|_(ツ)_/¯" << std::endl;
    }

    std::cout << ">>> Você está saindo do jogo com um total de $" << finalMoney << " créditos." << std::endl;
}