#include "roulette.h"
#include "bets.cpp"

int main()
{
    int selection;
    bool bet;
    int current_money;
    int base_money = 1000;
    std::cout << "Roulette game!\n\n" << "Please choose what you wish to do: "<< std::endl;
    std::cout << "Start new game (press [1]). \n" << "Continue game (press [2]). \n"<< "Exit (press [3])." << std::endl;


    std::cout << "Select the bet you would like to place: \n" << "Single bet (press [1])\n" << "Split bet (press [2])\n" << "Street bet (press [3])\n" << "Square bet (press [4])\n" << "Line bet (press [5])" << std::endl;
    std::cin>> selection;
    
    int random_number = winning_number();
    std::cout << random_number << std::endl;

   /* switch (selection) {
        case 1:
        {
        std::vector<int> vec = single_bet();
        bet = check_if_number_in_vector(random_number, vec);
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
        case 5:
        {
        std::vector<int> vec = line_bet();
        bet = check_if_number_in_vector(random_number,vec);
        break;
        }
        case 6:
        {
        std::vector<int> vec = collum_bet();
        bet = check_if_number_in_vector(random_number,vec);
        break;
        }
        case 7:
        {
        std::vector<int> vec = dozens_bet();
        bet = check_if_number_in_vector(random_number,vec);
        break;
        }
        case 8:
        {
        std::vector<int> vec = high_low_bet();
        bet = check_if_number_in_vector(random_number,vec);
        break;
        }
        case 9:
        {
        std::vector<int> vec = odd_even_bet();
        bet = check_if_number_in_vector(random_number,vec);
        break;
        }
        case 10:
        {
        std::vector<int> vec = red_black_bet();
        bet = check_if_number_in_vector(random_number,vec);
        break;
        }
    }
    */
    bool bet_won = check_bet(selection,random_number);

    std::cout << (bet_won ? "You won!" : "You lost.") << std::endl;
    
}