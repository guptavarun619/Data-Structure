#include<iostream>
using namespace std;
// (i,j) cordinates of currect cell
// (m,n) cordinates of last cell - final destination
bool ratMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n)
{
    // base case
    if(i==m && j==n)
    {
        soln[m][n] = 1;
        // print path
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    // rec case
    // Rat should be inside the grid
    if(i>m || j>n)
        return false;

    if(maze[i][j] == 'X')
        return false;

    // Assume solution exists through current cell
    soln[i][j] = 1;

    bool rightSuccess = ratMaze(maze, soln, i, j+1, m, n);
    bool downSuccess = ratMaze(maze, soln, i+1, j, m, n);

    // Backtracking
    soln[i][j] = 0;

    if(rightSuccess || downSuccess)
        return true;
    else
        return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int a, b;
    cin >> a >> b;
    char maze[10][10];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> maze[i][j];
            // cout << maze[i][j] << " ";
        }
        // cout << endl;
    }

    int soln[10][10] = {0};    

    bool ans = ratMaze(maze, soln, 0, 0, a-1, b-1);
    if(!ans)
        cout << "The Path doesn't exists" << endl;

    return 0;
}