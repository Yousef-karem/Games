#include <iostream>
//#include"../include/BoardGame_Classes.hpp"
#include "BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer and any number except 1 for another player : ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager x_o_game (new Tic_Tac_Toe_Board(), players);
    x_o_game.run();
    system ("pause");
}