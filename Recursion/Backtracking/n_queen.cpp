#include <bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
    for(int row = 0; row < i; row++)
    {
        if(board[row][j] == 1)
        {
            return false;
        }
    }

    // Check for the left diagonal
    int x = i, y = j;
    while(x>=0 && y>=0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    // Check for the right diagonal
    x = i;
    y = j;
    while(x>=0 && y<n)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }

    // If we get here so far, then the positon is safe to place a queen
    return true;
}

bool solveNQueen(int board[][10], int i, int n)
{
    // Base Case
    if(i==n)
    {
        // All n queens are placed sucessfully
        // Print the board
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << "_ ";
            }
            cout << endl;
        }

        return true;
    }

    // Recursive Case
    // Try to place the queen in the current row and call on the remaining part
    for(int j = 0; j < n; j++) 
    {
        // Check if (i,j) position is safe to place a queen or not
        if(isSafe(board, i, j, n))
        {
            // Place the Queen - Assuming i,j is the right position
            board[i][j] = 1;
            bool nextQueenPossible = solveNQueen(board,i+1, n);
            if(nextQueenPossible)
            {
                return true;
            }
            //Means i,j is not the right positon - Assumption is wrong
            board[i][j] = 0; //Backtrack 
        }
    }
    // You have tried for all position for the current row but couldn't place queen
    return false;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif    
    int n;
    cin >> n;
    int board[10][10] = {0};

    solveNQueen(board, 0, n);

    return 0;
}