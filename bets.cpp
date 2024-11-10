#include "logic.cpp" 

//.................
//.................
// INLINE BETS 
//.................
//.................

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

//.................
//.................
// OUTLINE BETS
//.................
//.................

std::vector<int> collum_bet(){

    int bet1;
    std::vector<int> collum;
    std::cout << "Collum bet - bet on one of the three collums, please select the collum you wish to bet on:\n";
    std::cout << "Type 1 for 1st collum (1 to 34)\n"<< "Type 2 for 2nd collum (2 to 35)\n" << "Type 3 for 3rd collum (3 to 36)\n";
    std::cin>>bet1;

    switch(bet1){
        case 1:
        {
        for (int i = 0; i < 12 ; i ++){
            collum.push_back(roulette_table[i][0]);
            }
        break;
        }
        case 2:
        {
        for (int i = 0; i < 12 ; i ++){
            collum.push_back(roulette_table[i][1]);
            }
        break;
        }
        case 3:
        {
        for (int i = 0; i < 12 ; i ++){
            collum.push_back(roulette_table[i][2]);
            }
        break;
        }
        default:
        std::cout<<"Invalid input\n";
    }

    return collum;
}

std::vector<int> dozens_bet(){

    int bet1;
    std::vector<int> dozen;
    std::cout << "Dozens bet - bet on any dozen from the roulette table\n";
    std::cout << "Type 1 for 1st dozen (1 to 12)\n"<< "Type 2 for 2nd dozen (13 to 24)\n" << "Type 3 for 3rd dozen (25 to 36)\n";
    std::cin>>bet1;

    switch(bet1){
        case 1:
        {
        for (int i = 1; i <= 12 ; i ++){
            dozen.push_back(i);
            }
        break;
        }
        case 2:
        {
        for (int i = 13; i <= 24 ; i ++){
            dozen.push_back(i);
            }
        break;
        }
        case 3:
        {
        for (int i = 25; i <= 36 ; i ++){
            dozen.push_back(i);
            }
        break;
        }
        default:
        std::cout<<"Invalid input\n";
    }

    return dozen;
}

std::vector<int> high_low_bet(){

    int bet1;
    std::vector<int> range;
    std::cout << "High or low bet - bet on either low numbers or high numebrs\n";
    std::cout << "Type 1 for low numbers (1 to 18)\n"<< "Type 2 for high numbers (19 to 36)\n";
    std::cin>>bet1;

    switch(bet1){
        case 1:
        {
        for (int i = 1; i <= 18 ; i ++){
            range.push_back(i);
            }
        break;
        }
        case 2:
        {
        for (int i = 19; i <= 36 ; i ++){
            range.push_back(i);
            }
        break;
        }
        default:
        std::cout<<"Invalid input\n";
    }

    return range;
}

std::vector<int> odd_even_bet(){

    int bet1;
    std::vector<int> range;
    std::cout << "Odd or even - bet on odd or even numbers\n";
    std::cout << "Type 1 for odd numbers\n"<< "Type 2 for even numbers\n";
    std::cin>>bet1;

    switch(bet1){
        case 1:
        {
        for (int i = 1; i <= 36 ; i ++){
            if (i%2!=0){
                range.push_back(i);
                }
            }
        break;
        }
        case 2:
        {
        for (int i = 1; i <= 36 ; i ++){
            if (i%2==0){
                range.push_back(i);
                }
            }
        break;
        }
        default:
        std::cout<<"Invalid input\n";
    }

    return range;
}

std::vector<int> red_black_bet(){

    int bet1;
    
    std::vector<int> range;
    std::cout << "Red or black bet - bet on either black or red numbers\n";
    std::cout << "Type 1 for red numbers\n"<< "Type 2 for black numbers\n";
    std::cin>>bet1;

    switch(bet1){
        case 1:
        {
        range.insert(range.begin(), red_numbers.begin(), red_numbers.end());
        break;
        }
        case 2:
        {
        range.insert(range.begin(), black_numbers.begin(), black_numbers.end());
        break;
        }
        default:
        std::cout<<"Invalid input\n";
    }

    return range;

}

//.................
//.................
// END OF BETS
//.................
//.................

bool check_bet(int selection, int random_number) {
    std::vector<int> vec;
    switch (selection) {
        case 1: vec = single_bet(); break;
        case 2: vec = split_bet(); break;
        case 3: vec = street_bet(); break;
        case 4: vec = square_bet(); break;
        case 5: vec = line_bet(); break;
        case 6: vec = collum_bet(); break;
        case 7: vec = dozens_bet(); break;
        case 8: vec = high_low_bet(); break;
        case 9: vec = odd_even_bet(); break;
        case 10: vec = red_black_bet(); break;
        default: return false;  
    }
    return check_if_number_in_vector(random_number, vec);
}
