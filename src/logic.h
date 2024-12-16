#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <string>
#include <limits>

extern int roulette_table[12][3];
extern std::vector<int> red_numbers;
extern std::vector<int> black_numbers;

int winning_number();
int get_valid_input_number_range(double min, double max);
int get_valid_input_number_vector(std::vector<int>& options);
std::vector<int> get_position(int x);
int get_number_at_position(int row, int collum);
std::vector<int> adjacent_numbers(int x);
std::vector<int> get_line(int x);
std::vector<std::vector<int>> get_square(int x);
std::vector<int> select_square(std::vector<std::vector<int>>& squares);
std::vector<std::vector<int>> get_adjacent_lines(int x);
std::vector<int> select_adjacent_lines(std::vector<std::vector <int>>& lines);
bool check_if_number_in_vector(int number, std::vector<int> vec);
bool numbers_match(int number1, int number2);

/*struct bet{
    double wager; 
    std::vector<int> numbers; 
    int type; 
    std::string name;
    int multiplier; 
};*/