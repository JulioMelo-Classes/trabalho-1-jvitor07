#ifndef KENOBET_H
#define KENOBET_H

#include <vector>
#include <random>
#include <time.h>
#include <array>
#include <chrono>
#include <thread>

#include <Teller.hpp>

using number_type = int; 
using cash_type = double; 
using set_of_numbers_type = std::vector<number_type>;

/*! 
 * Classe responsável por executar o jogo
 */
class KenoBet : public Teller
{
    private: cash_type m_wage = 0;
     number_type total_rounds;
     number_type current_round = 1;
     set_of_numbers_type m_spots;
     set_of_numbers_type random_numbers;
     set_of_numbers_type hits;
     
     public: std::vector<std::vector<double>> table{
         {0, 3},
         {0, 1, 9},
         {0, 1, 2, 16},
         {0, 0.5, 2, 6, 12},
         {0, 0.5, 1, 3, 15, 50},
         {0, 0.5, 1, 2, 3, 30, 75},
         {0, 0.5, 0.5, 1, 6, 12, 36, 100},
         {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
         {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
         {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
         {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
         {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
         {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
         {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
         {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}};
         
    public: bool set_wage(cash_type wage_);
     cash_type get_wage();
     void set_rounds(number_type rounds);
     number_type get_rounds();
     void next_round();
     number_type get_current_round();
     void set_m_spots(set_of_numbers_type numbers);
     set_of_numbers_type get_m_spots();
     void random_numbers_draw();
     set_of_numbers_type get_random_numbers();
     void set_hits();
     set_of_numbers_type get_hits();
     number_type get_hits_number();
     size_t size(void) const;
     void reset(void);
     void play();
};

#endif