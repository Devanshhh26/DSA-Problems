#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int row,int col,vector<vector<char>>&board,int n)
{
    int i=row;
    int j=col;

    // we only have to handle three cases i.e. (1)check for other queens at upper left diagnol (2)check for other queens at left (3) check for other queens at bottom left diagnol. 

    //left 
    while(j>=0)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
        j--;
    }
    i=row;
    j=col;

    // upper left diagnol
    while(i>=0 && j>=0)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
        i--;
        j--;
    }
    i=row;
    j=col;

    // bottom left diagnol
    while(i<n && j>=0)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void printSolution(vector<vector<char>>&board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(vector<vector<char>>&board,int col,int n)
{   
    // base case
    if(col>=n)
    {   //found correct position
        printSolution(board,n);
        return;
    }
    // for placing Queen at correct position in each row
    for(int row=0;row<n;row++)
    {   
        // solving one case
        if(isSafe(row,col,board,n))
        {   
            // recursion for one case
            board[row][col]='Q';
            // backtracking
            solve(board,col+1,n);
            // recusrion for undo
            board[row][col]='-';
        }
    }
}

int main()
{
    int n=4;
    vector<vector<char>>board(n,vector<char>(n,'-'));
    int col=0;
    solve(board,col,n);
    return 0;
}