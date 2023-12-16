// File name:Games.cpp
// Author(s):youssef karem wiliam-Arsany nageh Attia-juliana George
// ID(s):20220402-20220052-20221045
// Section:20
// Date:15/12/2023
#include<bits/stdc++.h>
using namespace std;
#include<BoardGame_Classes.hpp>
void Pyramic_Tic_Tac_Toe(){
    int choice;
    cout << "Welcome to FCAI Pyramic_Tic_Tac_Toe. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    Player *players[2];
    players[0]= new PY_Player(1, 'X');
    if (choice != 1)
        players[1] = new PY_Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);
    GameManager R(new PY_Board(),players);
    R.run();
}
void Connect_four_Game()
{
    int choice;
    cout << "Welcome to FCAI Connect-Four Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    Player *players[2];
    players[0]=new Player(1,'X');
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 6);
    GameManager R(new connectFour_Board,players);
    R.run();
}
int main()
{
    string message =R"(Welcome to FCAI games. :)
1-Pyramic Tic_Tac_Toe
2-Connect-Four game
_____________________
choose game :
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
        default:
            cout<<"The game is not valid\n";
    }
}
