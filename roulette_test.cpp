#include "roulette.h"
#include "logic.cpp"

int main()
{
    int bet;
    std::cin>> bet;

    std::cout<<"adjacent numbers for your bet: " <<std::endl;
    for (int adj : adjacent_numbers(bet)){
        std::cout << adj << " \n";
    }
    std::cout << std::endl;

}