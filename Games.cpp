// File name:Games.cpp
// Author(s):youssef karem wiliam-Arsany nageh Attia-juliana George
// ID(s):20220402-20220052-20221045
// Section:20
// Date:15/12/2023
#include<bits/stdc++.h>
using namespace std;
#include <BoardGame_Classes.hpp>
void Connect_four_Game()
{
    int choice;
    cout << "Welcome to FCAI Connect-Four Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    Player *players[2];
    players[0]=new connectFour_player(1,'X');
    if (choice != 1)
        players[1] = new connectFour_player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new New_RandomPlayer ('o',6,7);
    GameManager connectFour_game(new connectFour_Board,players);
    connectFour_game.run();
}
void Pyramic_Tic_Tac_Toe()
{
    int choice;
    cout << "Welcome to Pyramic_Tic_Tac_Toe Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    Player *players[2];
    players[0]=new PY_Player(1,'X');
    if (choice != 1)
        players[1] = new PY_Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new New_RandomPlayer ('o',5,3);
    GameManager Pyramic_Tic_Tac_Toe_game(new PY_Board,players);
    Pyramic_Tic_Tac_Toe_game.run();
}
void Tic_Tac_Toe ()
{
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI Tic_Tac_Toc Game. :)\n";
    cout << "Press 1 if you want to play with computer and any number except 1 for another player : ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new New_RandomPlayer ('o', 5,5);

    GameManager_Tic_Tac_Toc x_o_game (new Tic_Tac_Toe_Board(), players);
    x_o_game.run();

}
void X_O_Game()
{
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();
}
int main()
{
    string message =R"(Welcome to FCAI games. :)
1-Pyramic_Tic_Tac_Toe
2-Connect-Four
3-Tic_Tac_Toe
4-X_O
choose game from (1:4):
)";
    cout<<message;
    int choice;cin>>choice;
    switch (choice) {
        case 1:
            Pyramic_Tic_Tac_Toe();
            break;
        case 2:
            Connect_four_Game();
            break;
        case 3:
            Tic_Tac_Toe();
            break;
        case 4:
            X_O_Game();
            break;
        default:
            cout<<"The game is not valid\n";
    }
    system ("pause");
}
