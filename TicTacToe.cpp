#include <iostream>
#include <vector>
using namespace std;

//Function to print the board at any instant of game
void print(vector<vector<char>>& board)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
}

//Function to check if the player has won the game 
bool check(vector<vector<char>>& board, char player)
{
    //Loop to check if three consecutive character are present in a row or column
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
         return true;
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
         return true;
    }
    //To check the diagonal of the board if winning condition is satisfied
    if (board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;
    if (board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;

    return false;
}

//main Function
int main()
{
    vector<vector<char>> board(3,vector<char>(3,' '));
    //Intro and instructions
    cout<<"Welcome to the Tic-Tac-Toe game"<<endl;
    cout<<"General Instructions:"<<endl;
    cout<<"In this Game you have to fill a 3x3 board using a token provided to you,while your friend does the same."<<endl;
    cout<<"Whoever manages to fill any three consecutive squares on the board with their token first,wins the game."<<endl;
    cout<<"Now Player X is assigned token X and Player O is assigned token O.Player X starts the game."<<endl;
    cout<<"To fill the board,choose your required position in coordinates from (1,1) to (3,3)."<<endl;
    cout<<"If a Player Chooses already chosen square or an Invalid location out of bounds,he is given other chance."<<endl;
    cout<<"All the best,Have fun enjoying the game."<<endl;
    //curr denotes the current player
    char curr='X';
    //loop to run all nine moves of the game;
    for(int i=0;i<9;i++)
    {
        int row,col;
        cout<<"Player "<<curr<<",Enter your move:";
        cin>>row>>col;
        //convert to 0 based array indexing
        row--;
        col--;
        //Condition to fill the square and check wins and invalid conditions
        if(row>=0 && row<3 && col>=0 && col<3 && board[row][col]==' ')
        {
            board[row][col]=curr;
            //prints the board after every valid move
            print(board);
            if(check(board,curr))
            {
                cout<<"Player "<<curr<<" wins the game!"<<endl;
                break;
            }
            //Conditional Operator to Switch Players
            curr=(curr=='X')?'O':'X';
        }
        //Invalid position  Handling
        else
        {
            cout<<"Invalid Move.Try again"<<endl;
            i--;
        }
    }
    //Draw Condition
    if(!check(board,'X') && !check(board,'O'))
    {
        cout<<"Its a Draw!"<<endl;
    }
    return 0;
}