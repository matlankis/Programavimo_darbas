#include "roulette.h"

int roulette_table[12][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,11,12},
    {13,14,15},
    {16,17,18},
    {19,20,21},
    {22,23,24},
    {25,26,27},
    {28,29,30},
    {31,32,33},
    {34,35,36}
};

int winning_number(){

    srand(time(0));
    int random_number = (rand() % (36)) + 1;
    return random_number;
};

std::vector<int> single_bet(){
    std::cout << "Single number bet - bet on any number 0 - 36, enter the number you would like to bet on: " << std::endl;
    int bet;
    std::cin>> bet;
    return {bet};    
}

std::vector<int> split_bet(){
    std::cout << "Split bet - bet on any line separating two numbers, enter the two numbers which are separated by this line: " << std::endl;
    int bet1,bet2;
    std::cin>> bet1 >> bet2;
    return {bet1, bet2};
}