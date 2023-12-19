// File name:ConnectFour_Player.cpp
// Author(s):youssef karem wiliam
// ID(s):20220402
// Section:20
// Date:17/12/2023
#include "BoardGame_Classes.hpp"
connectFour_player::connectFour_player(int order, char symbol) : Player(order, symbol) {
}
void connectFour_player::get_move(int &x, int &y)
{
    cout << "\nPlease enter your move x (0 to 5) : ";
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
int ConnectFour_AI_Player::MinMax(int &x, int &y,bool maximize,int cnt)
{
    int choose_x,choose_y;
    if(ptr->is_winner())
    {
        return ((maximize)?1:-1);
    }
    else if (ptr->is_draw())
        return 0;
    int mx=INT_MIN,mn=INT_MAX;
    if(cnt==4)
        return ((maximize)?mn:mx);
    for (int j = 0; j <6; ++j) {
        for (int i = 6; i >=0 ; --i) {
            if((ptr->board[i][j])=='.')
            {
                ptr->board[i][j]=ptr->symbol;
                ptr->symbol=((maximize)?'O':'X');
                int result=MinMax(x, y, !maximize, cnt+1);
                ptr->symbol=ptr->board[i][j];
                ptr->board[i][j]='.';
                if(maximize&&result>mx)
                {
                    choose_x=i;
                    choose_y=j;
                    mx=result;
                    if(mx==1)
                    {
                        if(cnt==0)
                        {
                            x=choose_x;
                            y=choose_y;
                        }
                        return mx;
                    }
                }
                if(!maximize&&result<mn)
                {
                    choose_x=i;
                    choose_y=j;
                    mn=result;
                    if(mn==-1)
                    {
                        if(cnt==0)
                        {
                            x=choose_x;
                            y=choose_y;
                        }
                        return mn;
                    }
                }
                break;
            }

        }
    }
    if(cnt==0)
    {
        x=choose_x;
        y=choose_y;
    }
    return ((maximize)?mx:mn);
}

ConnectFour_AI_Player::ConnectFour_AI_Player(char symbol, Board *ptr): Player(symbol) ,ptr(ptr)
{
}
void ConnectFour_AI_Player::get_move(int &x, int &y)
{
    MinMax(x,y,0,0);
    ptr->board[x][y]='O';
    ptr->symbol='X';
    int a,b;
    if(last(a,b))
    {
        ptr->board[x][y]='.';
        x=a,y=b;
    }
    ptr->board[x][y]='.';
    ptr->symbol='O';
}

bool ConnectFour_AI_Player::last(int &a, int &b) {
    for (int j = 0; j <6; ++j) {
        for (int i = 6; i >=0 ; --i) {
            if(ptr->board[i][j]=='.')
            {
                ptr->board[i][j]='X';
                if(ptr->is_winner())
                {
                    ptr->board[i][j]='.';;
                    a=i,b=j;
                    return true;
                }
                ptr->board[i][j]='.';
                break;
            }
        }
    }
    return false;
}
