#include "logic.cpp" 

std::vector<int> single_bet(){

    std::cout << "Single number bet - bet on any number 0 - 36, enter the number you would like to bet on: " << std::endl;
    int bet;
    std::cin>> bet;
    return {bet};    
}

std::vector<int> split_bet(){

    int bet1,bet2;
    std::cout << "Split bet - bet on any line separating two numbers, enter the first number of the two:" << std::endl;
    std::cin>> bet1;
    std::vector<int> adjacent = adjacent_numbers(bet1);
    std::cout << "Available options for the second number "<<std::endl;
    for (int adj : adjacent){
        std::cout << adj << ", ";
        }
    std::cout << "\nEnter the second number, which is adjacent to the first one, that you wish to bet on: " << std::endl;
    std::cin>> bet2;
    while (check_if_number_in_vector(bet2, adjacent) != 1)
    {
            std::cout << "Entered number incorrect, please enter the number which is adjacent to the first" << std::endl;
            std::cin>> bet2;
    }
    return {bet1, bet2};
}

std::vector<int> street_bet(){

    int bet1;
    std::cout << "Street bet - bet on any line of 3 numbers from the outside of the line, please input a number of the line you wish to bet on: "<< std::endl;
    std::cin >> bet1;
    std::vector<int> line = get_line (bet1);
    std::cout << "Your numbers: "<<std::endl;
    for (int adj : line){
        std::cout << adj << ", ";
        }
    return line;
}

std::vector<int> square_bet(){

    int bet1;
    std::cout << "Square bet - bet on any intersection between 4 numbers, please input a number of the square you wish to bet on: "<< std::endl;
    std::cin>>bet1;
    std::vector<std::vector<int>> squares = get_square(bet1);
    
    return select_square(squares);
}

std::vector<int> line_bet(){

    int bet1;
    std::cout << "Line bet - bet on two adjacent rows of the roulette table, please input a number of the line you wish to bet on: "<< std::endl;
    std::cin>>bet1;
    std::vector<std::vector<int>> adjacent_lines = get_adjacent_lines(bet1);

    return select_adjacent_lines(adjacent_lines);
}