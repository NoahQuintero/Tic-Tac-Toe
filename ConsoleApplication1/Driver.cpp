// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "TicTacToeBoard.h"
#include "TicTacToeGame.h"

int main()
{
    std::cout << "Welcome to Tic Tac Toe!\n";

    std::cout << "How many players? ";

    // add some input checkin here

    int playersCount;
    char* players;
    int size;
    
    std::cin >> playersCount;

    std::cout << "\nEnter your player characters:";

    // one extra chacter for the sweet null terminator
    players = (char*)malloc((playersCount + 1) * sizeof(char));

    for (int i = 0; i < playersCount; i++) {
        std::cout << "\nPlayer " << i << ": ";

        std::cin >> players[i];
    }

    players[playersCount] = '\0';

    std::cout << "What is the size of the board?";

    std::cin >> size;

    std::cout << "Spectacular, let's play!\n";

    TicTacToeGame* game = new TicTacToeGame(playersCount, players, size);

    while (!game->is_game_won()) {

    }

}

void prompt_player_move() {

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
