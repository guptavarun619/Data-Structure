#include<iostream>
#include<climits>
using namespace std;

int main()
{
    // prefix sum matrix approach
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int row, col, tempSum = 0, maxSum = INT_MIN;
    cin >> row >> col;
    int a[row][col];

    // Input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }

    // Precalculated sum array
    for (int i = 0; i < col; i++)
    {
        int temp = 0;
        for (int j = 0; j < row; j++)
        {
            temp += a[j][i];
            a[j][i] = temp;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++)
    {
        int temp = 0;
        for (int j = 0; j < col; j++)
        {
            temp += a[i][j];
            a[i][j] = temp;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    // maxSum using pre sum array
    for (int tx = 0; tx < row; tx++)
    {
        for (int ty = 0; ty < col; ty++)
        {
            for (int bx = tx; bx < row; bx++)
            {   tempSum = 0;
                for (int by = ty; by < col; by++)
                {
                    tempSum = a[bx][by];
                    if(tx > 0)
                        tempSum -= a[tx - 1][by];
                    if(ty > 0)
                        tempSum -= a[bx][ty - 1];
                    if(tx > 0 && ty > 0)
                        tempSum += a[tx - 1][ty - 1];
                    maxSum = max(maxSum, tempSum);
                }
            }
        }
    }
    
    cout << "Maximum sum is : " << maxSum;

    return 0;
}