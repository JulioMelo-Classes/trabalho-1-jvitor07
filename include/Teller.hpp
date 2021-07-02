#ifndef TELLER_H
#define TELLER_H

#include <string>
#include <vector>
#include <iostream>

class Teller
{
    protected: void printHeader(int rounds, double totalWage, double roundWage);
     void printTable(std::vector<int> numbers, std::vector<double> tableLine);
     void printRound(double money, int currentRound, int roundTotal, std::vector<int> drawNumbers);
     void printRoundResult(std::vector<int> hits, int hitQuantity, int numbersTotal, double multiplier, double result, double total);
     void printSumary(double initialMoney, double finalMoney);
};

#endif