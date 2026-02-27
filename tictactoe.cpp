#include<iostream>
using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_player='X';

void drawBoard() 
{
    cout<<"\n";
    for(int i=0;i<3;i++) 
	{
        cout<<" ";
        for(int j=0;j<3;j++) 
		{
            cout<<board[i][j];
            if(j<2) 
			{
			cout << " | ";
			}
        }
        cout<<"\n";
        if(i<2) 
		{
			cout << "---|---|---\n";
		}
    }
    cout<<"\n";
}

bool checkWin() 
{
    for(int i=0;i<3;i++) 
	{
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return true;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return true;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return true;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return true;
    return false;
}

void switchPlayer() 
{
    current_player = (current_player=='X') ?'O':'X';
}

void makeMove(int position) 
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j] =='0' + position)
                board[i][j] = current_player;
}

int main() 
{
    int moves=0,pos;
    while(moves<9) 
	{
        drawBoard();
        cout<<"Player "<<current_player<<", enter your move (1-9): ";
        cin>>pos;
        makeMove(pos);
        if(checkWin()) 
		{
            drawBoard();
            cout<<"Player "<<current_player<<" wins!\n";
            return 0;
        }
        switchPlayer();
        moves++;
    }
    drawBoard();
    cout << "It's a draw!\n";
    return 0;
}