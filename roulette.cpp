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


    std::cout << "Select the bet you would like to place: \n" << "Single bet (press [1])\n" << "Split bet (press [2])\n" << "Street bet (press [3])\n" << "Square bet (press [4])" << std::endl;
    std::cin>> selection;
    
    int random_number = winning_number();
    std::cout << random_number << std::endl;

    switch (selection) {
        case 1:
        {
        std::vector<int> vec = single_bet();
        bet = check_if_number_in_vector(random_number, vec);
        //std::cout<<"adjacent numbers for your bet: " <<std::endl;
        //for (int adj : adjacent_numbers(bet)){
        //std::cout << adj << " \n";
        //}
        break;
        }
        case 2:
        {
        std::vector<int> vec = split_bet();
        bet = check_if_number_in_vector(random_number, vec);
        break;
        }
        case 3:
        {
        std::vector<int> vec = street_bet();
        bet = check_if_number_in_vector(random_number,vec);
        break;
        }
        case 4:
        {
        std::vector<int> vec = square_bet();
        bet = check_if_number_in_vector(random_number,vec);
        break;
        }
    }
    if (bet > 0)
    {
        std::cout<<"\nYou have won!" << std::endl;

    }
    else
    {
        std::cout<<"\nYou have lost." << std::endl;
    }
  
    std::cout << std::endl;
    
}