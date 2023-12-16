#include <iostream>
//#include"../include/BoardGame_Classes.hpp"
#include "BoardGame_Classes.hpp"
using namespace std;

GameManager_Tic_Tac_Toc::GameManager_Tic_Tac_Toc(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager_Tic_Tac_Toc::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}