#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
//#include "../include/BoardGame_Classes.hpp"
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
Tic_Tac_Toe_Board::Tic_Tac_Toe_Board () {
   n_rows = n_cols = 5;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Tic_Tac_Toe_Board::update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x >4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
    return false;
}

void Tic_Tac_Toe_Board::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n---------------------------------------------------";
    }
    cout << endl;
}

bool Tic_Tac_Toe_Board::is_winner() {
    int i, j;
    Player* players[2];
    Player* playerPtr[2];
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
   int  score_X=0,score_O=0;
    // check for 3-in-a-row
    for (i = 0; i < n_rows; i++) {
        for (j = 0; j < n_cols - 2; j++) {
            if (board[i][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
                if (board[i][j] == 'X') {
                    score_X++;
                } else if(board[i][j]=='O') {
                    score_O++;

                }}
            }
        }

    // check for 3-in-a-column
    for (i = 0; i < n_rows - 2; i++) {
        for (j = 0; j < n_cols; j++) {
            if (board[i][j] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j]) {
                if (board[i][j] == 'X') {
                    score_X++;
                } else if(board[i][j]=='O') {
                    score_O++;
                }
            }
        }
    }

    // check for 3-in-a-diagonal
    for (i = 0; i < n_rows - 2; i++) {
        for (j = 0; j < n_cols - 2; j++) {
            if (board[i][j] && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2]) {
                if (board[i][j] == 'X') {
                    score_X++;
                } else if(board[i][j]=='O'){
                    score_O++;
                }
            }
        }
    }

    // check for 3-in-a-reverse-diagonal
    for (i = 0; i < n_rows - 2; i++) {
        for (j = 2; j < n_cols; j++) {
            if (board[i][j] && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2]) {
                if (board[i][j] == 'X') {
                    score_X++;
                }else if(board[i][j]=='O'){
                    score_O++;
                }
            }
        }
    }


    // Check if we've reached the maximum number of moves
    if (n_moves == 24) {
        if (score_O > score_X|| score_X > score_O) {
            if(score_O>score_X){
                cout<<"Player 2 with Os" <<" is win by  "<<score_O<< " times  more than Player 1 loses with "<< score_X<<"\n";
            }
            else{
                cout<<"Player 1 with xs" <<" is win by "<<score_X<<" times  more than Player 2 loses with "<< score_O<<"\n";
            }
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}
bool Tic_Tac_Toe_Board::is_draw() {
    return (n_moves == 24 && !is_winner());
}


bool Tic_Tac_Toe_Board::game_is_over () {
    return n_moves >= 24;
}
void Tic_Tac_Toe_player::get_move(int &x, int &y) {
        cout << "\nPlease enter your move x and y (0 to 5) separated by spaces: ";
        cin >> x >> y;
}
Tic_Tac_Toe_player::Tic_Tac_Toe_player(int order, char symbol) : Player(order, symbol) {
}