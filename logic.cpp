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

std::vector<int> get_position(int x){

    std::vector<int> adjacent;
    //if (x < 1 || x > 36) {
     //   throw std::out_of_range("Number is not in range of roulette");
    //}

    int row = (x - 1)/3;
    int collum = (x - 1)%3;

    adjacent.push_back(row);
    adjacent.push_back(collum);

    return adjacent;
}
int get_number_at_position (int row, int collum)
{
    return row * 3 + collum +1;
}
    
std::vector<int> adjacent_numbers(int x){

    std::vector <int> position = get_position(x);
    int row = position.front();
    int collum = position.back();

    std::vector <int> adjacent;
    if (row - 1 >= 0){
        adjacent.push_back(get_number_at_position(row-1, collum));
    }
    if (row + 1 < 12){
        adjacent.push_back(get_number_at_position(row+1, collum));
    }
    if (collum - 1 >= 0){
        adjacent.push_back(get_number_at_position(row, collum-1));
    }
    if (collum + 1 < 3){
        adjacent.push_back(get_number_at_position(row, collum+1));
    }
    return {adjacent};
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