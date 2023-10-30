#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isSafe(int value,int board[9][9],int curr_row,int curr_col)
{
    // row check
    for(int col=0;col<9;col++)
    {
        if(board[curr_row][col]==value)
        {
            return false;
        }
    }

    // column check
    for(int row=0;row<9;row++)
    {
        if(board[row][curr_col]==value)
        {
            return false;
        }
    }

    //3*3 box
    for(int i=0;i<9;i++)
    {
        if(board[3*(curr_row/3)+(i/3)][3*(curr_col/3)+(i%3)]==value)
        {
            return false;
        }
    }

}

bool solve(int board[9][9],int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            // check for empty cell
            if(board[i][j]==0)
            {
                for(int value=1;value<=9;value++)
                {
                    if(isSafe(value,board,i,j))
                    {   
                        // insert
                        board[i][j]==value;
                        // recursion
                        bool aageKaSolution=solve(board,n);
                        if(aageKaSolution==true)
                        {
                            return true;
                        }
                        // backtracking
                        board[i][j]==0;
                        
                    }
                }
            }
        }
    }
    return false;

}

int main()
{
    int board[9][9]={ {},
                    {},
                    {},
                    {},
                    {},
                    {},
                    {},
                    {},
                    {}};
    int n=9;
    solve(board,n);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
    }
    return 0;
}