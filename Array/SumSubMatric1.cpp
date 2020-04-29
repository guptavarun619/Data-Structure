#include<iostream>
#include<climits>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int row, col, tempSum = 0, maxSum = INT_MIN;
    cin >> row >> col;
    int a[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
        
    }
    


    // Bruteforce method to find maximum sum for sub-array
    for (int tx = 0; tx < row; tx++)
    {
        for (int ty = 0; ty < col; ty++)
        {
            for (int bx = tx; bx < row; bx++)
            {
                for (int by = ty; by < col; by++)
                {
                    tempSum = 0;
                    for (int i = tx; i < bx + 1; i++)
                    {
                        for (int j = ty; j < by + 1; j++)
                        {
                            tempSum += a[i][j];
                        }
                        
                    }
                    maxSum = max(maxSum, tempSum);
                }
            }
        }
    }
    
    cout << maxSum;

    return 0;
}