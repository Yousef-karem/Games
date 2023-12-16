// File name:ConnectFour_Player.cpp
// Author(s):youssef karem wiliam
// ID(s):20220402
// Section:20
// Date:14/12/2023
#include "BoardGame_Classes.hpp"
connectFour_player::connectFour_player(int order, char symbol) : Player(order, symbol) {
}
void connectFour_player::get_move(int &x, int &y)
{
    cout << "\nPlease enter your move x (0 to 6) : ";
    cin >> y ;
}
New_RandomPlayer::New_RandomPlayer(char symbol, int dX, int dY): Player(symbol),dX(dX),dY(dY) {
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
    srand(unsigned (time(0)));
}
void New_RandomPlayer::get_move(int &x, int &y)
{
    x = (int) (rand()/(RAND_MAX + 1.0) * dX);
    y = (int) (rand()/(RAND_MAX + 1.0) * dY);
}
