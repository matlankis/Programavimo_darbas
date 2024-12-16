#include "roulette.h"

struct player_state{

    std::string name; //player name
    double money; //money the player has

};

void assign_player_stats(double money, std::string name){

    player_state player;
    player.name = name;
    player.money = money;

}

