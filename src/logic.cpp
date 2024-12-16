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

std::vector<int> red_numbers = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
std::vector<int> black_numbers = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};

int winning_number(){

    srand(time(0));
    int random_number = (rand() % (36)) + 1;
    return random_number;
};

int get_valid_input_number_range(double min, double max){

    double input;
    while (true){
        if(std::cin>>input){
            if(input >= min && input<= max){
                return input;
            }
            else{
                std::cout<< "Invalid number, please enter a number between " << min << " and " << max <<std::endl;
            }
        }
        else {
        std::cout<<"Invalid input. Please enter an integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int get_valid_input_number_vector(std::vector<int>& options){
    
    int input;
    while (true){
        if(std::cin>>input){
            for (int option : options){
                if (input == option){
                    return input;
                }
            }
            std::cout<< "Invalid number, please select a number from the given options\n";
        }
        else {
        std::cout<<"Invalid input. Please enter an integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

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
    //std::vector<int> square;
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

    int square_choice;
    std::cout<<"SQUARE OPTIONS:\n";
    for (int i = 0; i < squares.size(); i++){
        std::cout<<"\nSquare number " << i + 1<< ": "<< std::endl;
        for (auto sqr : squares[i]){
            std::cout<< sqr << " ";
        }
        std::cout << "\n";
    }
    std::cout<<"Select the square you wish to choose: "<<std::endl;
    square_choice = get_valid_input_number_range(1,squares.size());

    return squares[square_choice-1];
}
// TODO:
// modify this function
// there is probably a way to do this that is way better 
std::vector<std::vector<int>> get_adjacent_lines(int x){
    
    std::vector<int> index = get_position(x);
    std::vector<std::vector <int>> available_adjacent_lines;
    std::vector<int> current_line;

    int row = index.front();

    //available_adjacent_lines.push_back(get_line(x));

    if(row - 1 >= 0){
        current_line = get_line(x);
        std::vector<int> above_line = get_line(x-3);
        current_line.insert(current_line.begin(), above_line.begin(), above_line.end());
        available_adjacent_lines.push_back(current_line);
        current_line.clear();
    }
    
    if(row + 1 < 12){
        current_line = get_line(x);
        std::vector<int> below_line = get_line(x+3);
        current_line.insert(current_line.begin(), below_line.begin(), below_line.end());
        available_adjacent_lines.push_back(current_line);
        current_line.clear();
    }

    return available_adjacent_lines;
}

std::vector<int> select_adjacent_lines(std::vector<std::vector <int>>& lines){

    int adjacent_lines_choice;
    std::cout<<"ADJACENT LINE OPTIONS:";
    for(int i=0; i < lines.size(); i++){
        std::cout<<"\nLines number " << i + 1<< ": "<< std::endl;
        for (auto line : lines[i]){
            std::cout<< line << " ";
        }
        std::cout << "\n";
    }
    std::cout<<"Select the lines you wish to choose: "<<std::endl;
    adjacent_lines_choice=get_valid_input_number_range(1,lines.size());

    return lines[adjacent_lines_choice-1];
}

bool check_if_number_in_vector(int number, std::vector<int> vec){

    bool x = count(vec.begin(), vec.end(), number);
    return x;
}

bool numbers_match(int number1, int number2){

    return number1 == number2;
}

struct bet{
    double wager; //amount to bet on
    std::vector<int> numbers; //numbers the bet covers
    int type; // the bet type itself
    std::string name;
    int multiplier; //the multiplier for the winnings
};