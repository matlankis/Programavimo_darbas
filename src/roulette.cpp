#include "roulette.h"
//#include "bets.cpp"
//#include "player.cpp"
#include "game.cpp"

int main()
{

    std::string name;
    double money;
    int choice;
    
    std::cout << "Roulette game!\n\n";
    display_menu();
    choice = get_valid_input_number_range(1,3);

    if (choice == 1){

        std::cout << "Please enter your name\n";
        std::cin >> name;
        money = 1000;
        assign_player_stats(money, name);
    }
    else if (choice == 2){

        if(!load_game(name, money)){

            std::cout << "Starting a new game, since there are no saved games\n";
            std::cout << "Please enter your name\n";
            std::cin >> name;
            money = 1000;
            assign_player_stats(money, name);
        }
        
    }
    else if (choice == 3){
        std::cout << "Exiting the game.";
        return 0;
    }

    play_game(name, money);

}