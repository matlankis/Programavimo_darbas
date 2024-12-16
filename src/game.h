#include <filesystem>

#include "bets.h"

void display_menu();
void save_game(std::string player_name, double money);
bool load_game(std::string& playerName, double& money);
void play_game(std::string player_name, double money);