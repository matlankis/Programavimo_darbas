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

    std::vector<int> position;
    //if (x < 1 || x > 36) {
     //   throw std::out_of_range("Number is not in range of roulette");
    //}

    int row = (x - 1)/3;
    int collum = (x - 1)%3;

    position.push_back(row);
    position.push_back(collum);

    return position;
}

int get_number_at_position(int row, int collum)
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
}

std::vector<int> get_line(int x){

    std::vector<int> index = get_position(x);
    std::vector<int> line;
    line.push_back(x);
    int row = index.front();
    int collum = index.back();
    if (collum - 1 >= 0){
        line.push_back(get_number_at_position(row, collum-1));
    }
    if (collum + 1 < 3){
        line.push_back(get_number_at_position(row, collum+1));
    }
    if (collum - 2 >= 0){
        line.push_back(get_number_at_position(row, collum-2));
    }
    if (collum + 2 < 3){ 
        line.push_back(get_number_at_position(row, collum+2));
    }
    return line;
}

std::vector<std::vector<int>> get_square(int x){

    std::vector<int> index = get_position(x);
    std::vector<std::vector <int>> available_squares;
    std::vector<int> square;
    int row = index.front();
    int collum = index.back();

    if(row - 1 >= 0 && collum - 1 >= 0){
        available_squares.push_back({
            x,
            get_number_at_position(row - 1, collum - 1),  // diagonal
            get_number_at_position(row, collum - 1),      // left 
            get_number_at_position(row - 1, collum)       // top
        });
    }
    if(row + 1 < 12 && collum + 1 < 3){
        available_squares.push_back({
            x,
            get_number_at_position(row + 1, collum + 1),  // diagonal
            get_number_at_position(row, collum + 1),      // right
            get_number_at_position(row + 1, collum)       // below
        });
    }
    if(row + 1 < 12 && collum - 1 >= 0){
        available_squares.push_back({
            x,
            get_number_at_position(row + 1, collum - 1),  // diagonal
            get_number_at_position(row, collum - 1),      // left 
            get_number_at_position(row + 1, collum)       // below
        });
    }
    if(row - 1 >= 0 && collum + 1 < 3){
        available_squares.push_back({
            x,
            get_number_at_position(row - 1, collum + 1),  // diagonal
            get_number_at_position(row, collum + 1),      // right
            get_number_at_position(row -1, collum)       // top
        });
    }

    return available_squares;
}

std::vector<int> select_square(std::vector<std::vector<int>>& squares){

    std::cout<<"SQUARE OPTIONS:\n";
    for (int i = 0; i < squares.size(); ++i){
        std::cout<<"\nSquare number " << i + 1<< ": "<< std::endl;
        for (auto sqr : squares[i]){
            std::cout<< sqr << " ";
        }
        std::cout << "\n";
    }

}

int check_if_number_in_vector(int number, std::vector<int> vec){

    int x = count(vec.begin(), vec.end(), number);
    return x;
}

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
    select_square(squares);
    
    return {1};
}