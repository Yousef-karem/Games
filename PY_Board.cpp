// File name:PY_Board
// Purpose:Pyramic Tic-Tac-Toe
// Author(s):Arsany Nageh Attia
// ID(s):20220052
// Section:S19
// Date:12/12/2023
#include "BoardGame_Classes.hpp"


using namespace std;
PY_Board::PY_Board()  {
    n_rows =3;
    n_cols =5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool PY_Board::update_board(int x, int y, char mark) {
    if((x>2||x<0)&&(y>4||y<0)){
        return false;
    }
    else if (x == 0 && y != 2) {
        return false;
    } else if (x == 1 && (y == 4 || y == 0)) {
        return false;
    } else if (x > 2 || y > 4) {
        return false;
    }
    if (board[x][y] != 0) {
        return false;
    }
    board[x][y] = toupper(mark);
    n_moves++;
    return true;

}

void PY_Board::display_board() {
    for (int i: {0, 1, 2}) {
        cout << "\n";
        for (int j: {0, 1, 2, 3, 4}) {
            if(i==0&&j!=2){
                cout<<"         ";
            }else if(i==1&&(j==0||j==4)){
                cout<<"         ";

            }else {
                if(board[i][j] == 'X' || board[i][j] == 'O')
                    cout <<  "|   " << board[i][j]<<"   |";
                else {
                    cout << "| (" << i << "," << j << ")";
                    cout << board[i][j] << "|";
                }
            }}if(i==0){
            cout << "\n                  ---------";

        }else if(i==1){
            cout << "\n         ---------------------------";

        }else {
            cout << "\n---------------------------------------------";

        }
    }cout << endl;
}

bool PY_Board::is_winner() {
    char row_win[4], col_win[1], diag_win[2];
    for (int i: {0, 1, 2}) {
        row_win[i] = board[2][i] & board[2][i + 1] & board[2][i + 2];
    }
    row_win[3] = board[1][1] & board[1][2] & board[2][3];
    col_win[0] = board[0][2] & board[1][2] & board[2][2];
    diag_win[0] = board[0][2] & board[1][3] & board[2][4];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i: {0, 1, 2}) {
        if ((row_win[i] && (row_win[i] == board[2][i]))) { return true; }
    }
    if ((diag_win[0] && diag_win[0] == board[0][2]) ||
        (diag_win[1] && diag_win[1] == board[0][2]) ||
        (row_win[3] && row_win[3] == board[1][1]) ||
        (col_win[0] && col_win[0] == board[2][2])) { return true; }
    return false;
}

bool PY_Board::is_draw() {
    return (n_moves == 9 && !is_winner());

}

bool PY_Board::game_is_over() {
    return n_moves >= 9;

}
void PY_Player::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x (0 to 2) and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

PY_Player::PY_Player(int order, char symbol) : Player(order,symbol) {

}

//bool PY_Board::is_valid(int &x, int &y) {
//    if (x == 0 && y != 2) {
//        return false;
//    } else if (x == 1 && (y == 4 || y == 0)) {
//        return false;
//    } else if (x > 2 || y > 4) {
//        return false;
//    }
//    if (board[x][y] != 0) {
//        return false;
//    }
//    return true;
//}

