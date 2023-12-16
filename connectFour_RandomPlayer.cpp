// File name:ConnectFour_RandomPlayer.cpp
// Author(s):youssef karem wiliam
// ID(s):20220402
// Section:20
// Date:14/12/2023
#include "BoardGame_Classes.hpp"
connectFour_RandomPlayer::connectFour_RandomPlayer(char symbol, int dX, int dY): Player(symbol,2),dX(dX),dY(dY) {
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
    srand(unsigned (time(0)));
}
void connectFour_RandomPlayer::get_move(int &x, int &y)
{
    x = (int) (rand()/(RAND_MAX + 1.0) * dX);
    y = (int) (rand()/(RAND_MAX + 1.0) * dY);
}