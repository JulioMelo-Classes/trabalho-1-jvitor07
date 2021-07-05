#include "KenoBet.hpp"

#include <iostream>

/*! 
 * Retorna o valor que o jogador possui na carteira.
 * @return this->m_wage quantidade créditos.
 */
cash_type KenoBet::get_wage()
{
    return this->m_wage;
}

/*! 
 * @param wage_ quantidade de créditos.
 * @return bool validação pra saber se há créditos na carteira 
 */
bool KenoBet::set_wage(cash_type wage_)
{
    this->m_wage = wage_;

    return this->m_wage > 0 ? true : false;
}

/*! 
 * Retorna a quantidade de rounds.
 * @return this->total_rounds quantidade de rounds.
 */
number_type KenoBet::get_rounds()
{
    return this->total_rounds;
}

/*! 
 * Atribui a quantidade de rounds.
 * @return void.
 */
void KenoBet::set_rounds(number_type rounds)
{
    this->total_rounds = rounds;
}

/*! 
 * Retorna o round atual.
 * @return this->current_round round atual.
 */
number_type KenoBet::get_current_round()
{
    return this->current_round;
}

/*! 
 * Incrementa +1 no round atual.
 * @return void.
 */
void KenoBet::next_round()
{
    this->current_round += 1;
}

/*! 
 * Retorna os números selecionados pelo jogador.
 * @return this->m_spots número selecionados pelo jogador.
 */
set_of_numbers_type KenoBet::get_m_spots()
{
    return this->m_spots;
}

/*! 
 * Atribui os números selecionados pelo jogador.
 * @return void.
 */
void KenoBet::set_m_spots(set_of_numbers_type numbers)
{
    this->m_spots = numbers;
}

/*! 
 * Gera os números da rodada.
 * @return void.
 */
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

/*! 
 * Atribui os números gerados da rodada.
 * @return this->random_numbers retorna o vetor de números gerados.
 */
set_of_numbers_type KenoBet::get_random_numbers()
{
    return this->random_numbers;
}

/*! 
 * Verifica quais números sorteados o jogador acertou.
 * @return void.
 */
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

/*! 
 * Retorna um vetor com os acertos do jogador
 * @return this->hits vetor com números que o jogador acertou
 */
set_of_numbers_type KenoBet::get_hits()
{
    return this->hits;
}

/*! 
 * Retorna a quantidade de números que o jogador acertou
 * @return this->hits.size() quantidade de números que o jogador acertou
 */
number_type KenoBet::get_hits_number()
{
    return this->hits.size();
}

/*! 
 * Retorna o tamanho do jogo do jogador
 * @return this->m_spots.size() quantidade de números que o jogador escolheu
 */
size_t KenoBet::size(void) const
{
    return this->m_spots.size();
}

/*! 
 * Reseta o jogo para o valor inicial
 * @return void
 */
void KenoBet::reset(void)
{
    this->m_wage = 0;
    this->m_spots.clear();
}

/*! 
 * Executa a rotina do jogo, printando os dados e os resultados
 * @return void
 */
void KenoBet::play()
{
    double initialMoney = this->get_wage();
    double bet_amount = this->m_wage /this->total_rounds;

    this->printHeader(this->get_rounds(), initialMoney, initialMoney / this->get_rounds());
    this->printTable(this->get_m_spots(), this->table[this->size() - 1]);
    
    while(this->current_round <= this->total_rounds)
    {
        this->m_wage = this->m_wage - bet_amount;
        this->random_numbers_draw();
        this->set_hits();
        std::vector<int> arrHits = this->get_hits();
        double multiplier = this->table[this->size() - 1][this->get_hits_number()];
        double balance_bet = bet_amount * multiplier;
        this->m_wage += balance_bet;
        
        this->printRound(initialMoney / this->get_rounds(), this->get_current_round(), this->get_rounds(), this->get_random_numbers());
        this->printRoundResult(arrHits, arrHits.size(), this->get_m_spots().size(), multiplier, balance_bet, this->get_wage());
        
        this->next_round();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        this->random_numbers_draw();
    }

    this->printSumary(initialMoney, this->m_wage);
}   