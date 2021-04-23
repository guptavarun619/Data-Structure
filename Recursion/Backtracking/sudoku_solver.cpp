#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mat[][9], int i, int j, int n, int number) {
    // check the row and column  for number
    for(int x = 0; x < n; x++) {
        if(mat[i][x] == number || mat[x][j] == number)
            return false;
    }
    

    // check the smaller box for the number
    int x = (i/sqrt(n))*sqrt(n) , y = (j/sqrt(n))*sqrt(n) ;
    for(int a = x; a <= x+sqrt(n); a++) {
        for(int b = y; b <= y+sqrt(n); b++) {
            if(mat[a][b] == number)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n) {
    // Base Case
    if(i == n) {
        // Print the matrix
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }
    
    // incase row ends
    if(j==n) {
        return solveSudoku(mat, i+1, 0, n);
    }
    
    // Skip the pre-filled cells
    if(mat[i][j] != 0) {
        return solveSudoku(mat, i, j+1, n);
    }

    // Recursive Case
    // Fill the current cell with possible options
    for(int number = 1; number <=n; number++) {
        if(isPossible(mat, i, j, n, number) == true) {
            // Assuming this number is apt for this place
            mat[i][j] = number;

            bool solvable = solveSudoku(mat, i, j+1, n);
            if(solvable == true) {
                return true;
            }
        }
        
    }
    
    // Backtrack Condition - some previous value is not allowing to solve sudoku
    mat[i][j] = 0;
    return false;

}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif    
    int mat[9][9] = 
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,0,8,0,0,7,9}
    };

    bool ans = solveSudoku(mat, 0, 0, 9);
    // cout << ans;
    return 0;
}