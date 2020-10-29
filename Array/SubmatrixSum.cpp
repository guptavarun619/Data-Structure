#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int a[100][100], row, col, sum = 0;
    int tx, ty, bx, by;

    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }        
    }

    cin >> tx >> ty >> bx >> by;

    // creating pre-sum matrix
    int temp;
    for (int i = 0; i < row; i++)
    {
        temp = 0;
        for (int j = 0; j < col; j++)
        {
            temp += a[i][j];
            a[i][j] = temp;
        }
    }

    for (int i = 0; i < col; i++)
    {
        temp = 0;
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
    
    sum += a[bx][by];
    if(tx > 0)
        sum -= a[tx - 1][by];
    if(ty > 0)
        sum -= a[bx][ty -1];
    if(tx > 0 && ty > 0)
        sum += a[tx - 1][ty - 1];

    cout << sum;

    return 0;
}