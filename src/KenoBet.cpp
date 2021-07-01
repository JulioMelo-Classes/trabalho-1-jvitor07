#include "KenoBet.hpp"

#include <iostream>

cash_type KenoBet::get_wage()
{
    return this->m_wage;
}

bool KenoBet::set_wage(cash_type wage_)
{
    this->m_wage = wage_;

    return this->m_wage > 0 ? true : false;
}

number_type KenoBet::get_rounds()
{
    return this->total_rounds;
}

void KenoBet::set_rounds(number_type rounds)
{
    this->total_rounds = rounds;
}

number_type KenoBet::get_current_round()
{
    return this->current_round;
}

void KenoBet::next_round()
{
    this->current_round += 1;
}

set_of_numbers_type KenoBet::get_m_spots()
{
    return this->m_spots;
}

void KenoBet::set_m_spots(set_of_numbers_type numbers)
{
    this->m_spots = numbers;
}

void KenoBet::random_numbers_draw()
{
    this->random_numbers.clear();
    for(int i = 0; i < 20; i++)
    {
        srand((unsigned)time(NULL));
        int value = rand()%(80)+1;

        for(int j = 0; j < i; j++){
            if(value == this->random_numbers.at(j)){
                j = -1;
                value = rand()%(80)+1;
            }
        }

        this->random_numbers.push_back(value);
    }
}

set_of_numbers_type KenoBet::get_random_numbers()
{
    return this->random_numbers;
}

void KenoBet::set_hits()
{
    this->hits.clear();
    for(set_of_numbers_type::iterator itOne = this->m_spots.begin(); itOne != this->m_spots.end(); itOne++)
    {
        for(set_of_numbers_type::iterator itTwo = this->random_numbers.begin(); itTwo != this->random_numbers.end(); itTwo++)
        {
            if(*itOne == *itTwo) this->hits.push_back(*itOne);
        }
    }
}

set_of_numbers_type KenoBet::get_hits()
{
    return this->hits;
}

number_type KenoBet::get_hits_number()
{
    return this->hits.size();
}

size_t KenoBet::size(void) const
{
    return this->m_spots.size();
}

void KenoBet::reset(void)
{
    this->m_wage = 0;
    this->m_spots.clear();
}

void KenoBet::play()
{
    double initialMoney = this->get_wage();
    double bet_amount = this->m_wage /this->total_rounds;

    this->printHeader(this->get_rounds(), initialMoney, initialMoney / this->get_rounds());
    //this->printTable(this->get_m_spots(), this->table[this->size()]);
    
    while(this->current_round <= this->total_rounds)
    {
        this->m_wage = this->m_wage - bet_amount;
        this->random_numbers_draw();
        this->set_hits();
        std::vector<int> arrHits = this->get_hits();
        double multiplier = this->table[this->get_m_spots().size() - 1][this->get_hits_number()];
        double balance_bet = bet_amount * multiplier;
        this->m_wage += balance_bet;
        
        this->printRound(initialMoney / this->get_rounds(), this->get_current_round(), this->get_rounds(), this->get_random_numbers(), this->get_hits(), this->get_hits().size(), this->get_m_spots().size(), multiplier, balance_bet, this->get_wage());
        
        this->next_round();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        this->random_numbers_draw();
    }

    this->printSumary(initialMoney, this->m_wage);
}   