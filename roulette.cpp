#include "roulette.h"
#include "bets.cpp"

int main()
{
    int selection;
    std::cout << "Roulette game!\n\n"<< std::endl;

    int random_number = winning_number();
    std::cout << random_number << std::endl;   

    std::vector<bet> bets = place_bets();

    check_if_won(bets, random_number);

    
}