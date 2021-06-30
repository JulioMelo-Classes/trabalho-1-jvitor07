#include <iostream>
#include <vector>
#include <fstream>

#include "Interpreter.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    try{
        Interpreter *inter = new Interpreter(argv[1]);
        inter->openFile();
        inter->setText();
        std::vector<std::string> lines = inter->getText();
        inter->setNumbers();
        std::vector<int> numbers = inter->getNumbers();
        /*
        for(std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); it++)
        {
            cout << *it << endl;
        }
        */
        for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        {
            cout << *it << endl;
        }

    }catch(const char *msg){
        cerr << msg << endl;
    }

    return 0;
}