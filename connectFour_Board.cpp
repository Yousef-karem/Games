// File name:ConnectFour_Board.cpp
// Author(s):youssef karem wiliam
// ID(s):20220402
// Section:20
// Date:14/12/2023
#include "BoardGame_Classes.hpp"
bool connectFour_Board::update_board(int x=0, int y=0, char mark=0) {
    for (int i = n_rows-1; i >=0 ; --i) {
        if(board[i][y]=='.') {
            {
                board[i][y] = mark;
                n_moves++;
                return true;
            }
        }
    }
    return false;
}

void connectFour_Board::display_board() {
    for (int i = 0; i < n_cols; ++i) {
        cout<<setw(1)<<'('<<i<<')'<<' ';
    }
    cout<<'\n';
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            cout<<setw(2) << board [i][j]<<"  ";
        }
        cout<<'\n';
    }
}

bool connectFour_Board::game_is_over() {
    return (n_moves==n_rows*n_cols);
}

bool connectFour_Board::is_draw() {
    if(n_moves==n_rows*n_cols&&!is_winner())
        return true;
}
bool connectFour_Board::is_winner() {
    for (int i = 0; i < n_rows; ++i) {
        int cnt=0;
        for (int j = 0; j < n_cols; ++j) {
            if(board[i][j]!=symbol)
            {
                cnt=0;
                continue;
            }
            cnt++;
            if(cnt==4)
                break;
        }
        if(cnt==4)
            return true;
    }
    for (int i = 0; i < n_cols; ++i) {
        int cnt=0;
        for (int j = 0; j < n_rows; ++j) {
            if(board[j][i]!=symbol)
            {
                cnt=0;
                continue;
            }
            cnt++;
            if(cnt==4)
                break;
        }
        if(cnt==4)
            return true;
    }
    int dx[]={1,1,-1,-1};
    int dy[]={1,-1,1,-1};
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if(board[i][j]==symbol) {
                for (int k = 0; k < 4; ++k) {
                    int x = i, y = j;
                    int cnt = 0;
                    while (((x < n_rows && y < n_cols) && (x >= 0 && y >= 0)) && board[x][y] == symbol) {
                        cnt++;
                        if (cnt == 4)
                            return true;
                        x += dx[k], y += dy[k];
                    }
                }
            }
        }
    }
    return false;
}

connectFour_Board::connectFour_Board() {
    n_rows = 7;
    n_cols = 6;
    n_moves = 0;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            board[i][j] = '.';
        }
    }
}