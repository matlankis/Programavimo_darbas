#include "roulette.h"
#include "bets.cpp"
#include "player.cpp"



void display_menu(){

    std::cout << "Please choose what you would like to do: \n";
    std::cout << "1: Start new game\n";
    std::cout << "2: Continue existing game\n";
    std::cout << "3: Exit\n";
    std::cout << "Enter your choice (1, 2 or 3)\n";

}

void save_game(std::string player_name, double money){

    std::string fileName = "saves/" + player_name + ".txt";
    std::ofstream saveFile(fileName);
    saveFile << player_name << "\n";
    saveFile << money << "\n";

    saveFile.close();
    std::cout << "Saved game successfully\n";

}

bool load_game(std::string& playerName, double& money) {

    std::string path = "./saves";
    std::vector <std::string> fileNames;

    for (const auto & entry : std::filesystem::directory_iterator(path)){
        fileNames.push_back(entry.path().string());
    }

    if (fileNames.empty()) {
        std::cout<< "No saved games found\n";
        return false;
    }

    std::cout<< "Available saves:\n";
    for (size_t i = 0; i<fileNames.size(); i++){
        std::cout << i+1 << ". " << fileNames[i] << "\n";
    }

    int choice;
    std::cout << "Enter the number of the save you wish to load: \n";
    std::cin >> choice;

    if (choice < 1 || choice > fileNames.size()){
        std::cout<< "Invalid choice\n";
        return false;
    }

    std::string fileName  = fileNames[choice-1];

    std::ifstream loadFile(fileName); 
    if (!loadFile) {
        std::cout << "No save file found.\n";
        return false;
    }

    std::getline(loadFile, playerName);
    loadFile >> money;               

    loadFile.close();
    std::cout << "Game loaded successfully! Welcome back, " << playerName << ".\n";
    return true;
}

void play_game(std::string player_name, double money){

    char playChoice;
    char saveChoice;
    int count;
    
    std::cout<< "\nHello, " << player_name;
    do{
        std::cout << "!\nYou have $" << money << ".\n";
        std::cout << "Would you like to play a round? (y/n)\n";
        std::cin >> playChoice;
        if (playChoice == 'y' || playChoice == 'Y'){
             int random_number = winning_number();
            std::cout << random_number << std::endl;   

            std::vector<bet> bets = place_bets();
            check_if_won(bets, random_number, money);
            std::cout << "Your current balance is: " << money;
        }
        else if (playChoice == 'n' || playChoice == 'N'){
            std::cout << "Would you like to save your game? (y/n)\n";
            std::cin >> saveChoice;
            
            if (saveChoice == 'y' || saveChoice == 'Y'){
                save_game(player_name, money);
            }

            break;
        }
    }
    while (playChoice == 'y' || playChoice == 'Y');

}