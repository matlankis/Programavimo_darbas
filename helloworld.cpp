#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    int bet;
    std::cout << "Roulette game " << std::endl;
    std::cout << "Enter your bet" << std::endl;
    std::cin>> bet;

    int roulette_numbers[3][12] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18, 19, 20 , 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 , 36}
    };

    srand(time(0));
    //int random_number = (rand() % (36 - 1 + 1)) + 1;
    int random_number = (rand() % (36)) + 1;
    std::cout << random_number << std::endl;

    if (bet == random_number)
    {
        std::cout<<"You have won!" << std::endl;

    }
    else
    {
        std::cout<<"You have lost." << std::endl;
    }
    
}