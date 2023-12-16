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
