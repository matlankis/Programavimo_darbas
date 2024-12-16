#include <map>

#include "logic.h"

std::vector<int> single_bet();
std::vector<int> split_bet();
std::vector<int> street_bet();
std::vector<int> square_bet();
std::vector<int> line_bet();
std::vector<int> collum_bet();
std::vector<int> dozens_bet();
std::vector<int> high_low_bet();
std::vector<int> odd_even_bet();
std::vector<int> red_black_bet();

//std::map <int, std::string> bet_names;
//std::map <std::string, int> multipliers;

std::vector<bet> place_bets(double& money);

double check_if_won(std::vector<bet> bets, int winning_number, double& money);