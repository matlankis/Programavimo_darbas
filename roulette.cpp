#include "roulette.h"
#include "logic.cpp"

int main()
{
    int selection;
    int bet;
    int current_money;
    int base_money = 1000;
    std::cout << "Roulette game!\n\n" << "Please choose what you wish to do: "<< std::endl;
    std::cout << "Start new game (press [1]). \n" << "Continue game (press [2]). \n"<< "Exit (press [3])." << std::endl;


    std::cout << "Select the bet you would like to place: \n" << "Single bet (press [1])\n" << "Split bet (press [2])" << std::endl;
    std::cin>> selection;
    
    int random_number = winning_number();
    std::cout << random_number << std::endl;

    switch (selection) {
        case 1:
        {
        std::vector<int> vec = single_bet();
        bet = count(vec.begin(), vec.end(), random_number);
        break;
        }
        case 2:
        {
        std::vector<int> vec = split_bet();
        bet = count(vec.begin(), vec.end(), random_number);
        break;
        }
    }
    if (bet > 0)
    {
        std::cout<<"You have won!" << std::endl;

    }
    else
    {
        std::cout<<"You have lost." << std::endl;
    }
    
}