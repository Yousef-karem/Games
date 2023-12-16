// File name:Games.cpp
// Author(s):youssef karem wiliam-Arsany nageh Attia-juliana George
// ID(s):20220402-20220052-20221045
// Section:20
// Date:15/12/2023
#include<bits/stdc++.h>
using namespace std;
#include<BoardGame_Classes.hpp>
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
        players[1] = new connectFour_RandomPlayer ('o',6,7);
    GameManager R(new connectFour_Board,players);
    R.run();
}
int main()
{
    string message =R"(Welcome to FCAI games. :)
1-Connect-Four game
choose game :
)";
    cout<<message;
    int choice;cin>>choice;
    switch (choice) {
        case 1:
            Connect_four_Game();
            break;
        default:
            cout<<"The game is not valid\n";
    }
}
