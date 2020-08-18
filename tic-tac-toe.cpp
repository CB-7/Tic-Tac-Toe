#include<bits/stdc++.h>
using namespace std;

#define SIDE 3


void showBoard(char board[][SIDE])
{
    cout<<endl;

    cout<< board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"---------"<<endl;
    cout<< board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"---------"<<endl;
    cout<< board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;

    return;
}


void showInstructions()
{
    cout<<"Tic-Tac-Toe"<<endl;
    cout<<"------------"<<endl<<endl;
    cout<<"Choose a cell coordinates x and y as given below and play " <<endl<<endl;

    cout<<" 0,0 | 0,1  | 0,2 "<<endl;
    cout<<"------------------"<<endl;
    cout<<" 1,0 | 1,1  | 1,2 "<<endl;
    cout<<"------------------"<<endl;
    cout<<" 2,0 | 2,1  | 2,2 "<<endl;

    cout<<endl;
    return;
}


void initialise(char board[][SIDE])
{

    srand(time(NULL));


    for (int i=0; i<SIDE; i++)
    {
        for (int j=0; j<SIDE; j++)
            board[i][j] = ' ';
    }



    return;
}


void declareWinner(string whoseTurn)
{
    cout<<endl<<endl;

    cout<<whoseTurn<<" wins the game..."<<endl;
    return;
}


bool rowCheck(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return true;
    }
    return false;
}


bool columnCheck(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return true;
    }
    return false;
}


bool diagonalCheck(char board[][SIDE])
{
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
         board[0][2] != ' ')
        return true;

    return false;
}


bool gameOver(char board[][SIDE])
{
    return(rowCheck(board) || columnCheck(board)
            || diagonalCheck(board) );
}


void playTicTacToe()
{

    char board[SIDE][SIDE];

    initialise(board);
    showInstructions();

    int moves = 0, x, y;
    string player1,player2;
    string whoseTurn;
    cout<<"Enter name of player1 :";
    cin>>player1;
    cout<<"Enter name of player2 :";
    cin>>player2;
    cout<<endl;

    whoseTurn=player1;
    char player1_move,player2_move;


    player1_move='X';
    player2_move='O';

    cout<<player1<<" will play with "<<player1_move<<endl;
    cout<<player2<<" will play with "<<player2_move<<endl<<endl;
    cout<<player1<<" will play first"<<endl<<endl;



    while (gameOver(board) == false &&
            moves != SIDE*SIDE)
    {
        if (whoseTurn == player1)
        {
            check1:
            cout<<endl;
            cout<<player1<<"  turn:"<<endl;
            cout<<"Enter x coordinates:";
             cin>>x ;
            cout<<"Enter y coordinates:";
             cin>>y;
             cout<<endl<<endl;
             if(x>=0 && x<SIDE && y>=0 && y<SIDE && board[x][y]==' ')
             {
               board[x][y] = player1_move;
               cout<<player1<<" has put a "<<player1_move<<" in "<<x<<" , "<<y<<" cell."<<endl;

               moves++;
               showBoard(board);
               whoseTurn = player2;
             }
             else
             {
                 cout<<"Invalid Move!!!"<<endl;
                 cout<<"Please make a valid move"<<endl;
                 goto check1;
             }

        }

        else if (whoseTurn == player2)
        {
            check2:
            cout<<endl;
           cout<<player2<<" turn:"<<endl;
            cout<<"Enter x coordinates:";
             cin>>x ;
            cout<<"Enter y coordinates:";
             cin>>y;
             cout<<endl<<endl;

             if(x>=0 && x<SIDE && y>=0 && y<SIDE && board[x][y]==' ')
             {
                  board[x][y] = player2_move;
                  cout<<player2<<" has put a "<<player2_move<<" in "<<x<<" , "<<y<<" cell."<<endl;

                  moves++;
                  showBoard(board);
                  whoseTurn = player1;
             }
             else
             {
                  cout<<"Invalid Move!!!"<<endl;
                 cout<<"Please make a valid move"<<endl;
                 goto check2;
             }

        }


    if (gameOver(board) == false && moves == SIDE * SIDE)
        cout<<endl<<endl<<"  Its a draw !!!"<<endl;
    else if(gameOver(board))
    {
        if (whoseTurn == player1)
             whoseTurn = player2;
        else if (whoseTurn == player2)
            whoseTurn = player1;


        declareWinner(whoseTurn);
    }

    }
    return;
}


int main()
{

    playTicTacToe();

    return 0;
}
