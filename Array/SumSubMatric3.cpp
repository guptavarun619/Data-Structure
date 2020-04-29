#include<iostream>
#include<climits>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    int row, col, Sum = 0;
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

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            Sum += a[i][j] * ( ((i+1)*(j+1)) * ((row - i)*(col - j)) );
        }
    }
    
    cout << "Total subArray sum is : " << Sum;

    return 0;
}