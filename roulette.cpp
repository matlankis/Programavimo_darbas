#include "roulette.h"
#include "bets.cpp"
#include "player.cpp"


int main()
{

    int selection;
    std::string name;
    std::cout << "Roulette game!\n\n"<< std::endl;
    std::cout << "Please enter your name\n"<< std::endl;
    std::cin >> name;
    double money = 1000;
    assign_player_stats(money, name);


    int random_number = winning_number();
    std::cout << random_number << std::endl;   

    std::vector<bet> bets = place_bets();

    check_if_won(bets, random_number, money);

    std::cout<< "Your current balance is: " << money;

    
}