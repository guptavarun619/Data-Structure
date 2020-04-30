#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int m, n;
    cin >> m >> n;

    int a[10][10];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        } 
    }

    int rowStart = 0;
    int rowEnd = m - 1;
    int colStart = 0;
    int colEnd = n - 1;

    while(rowStart <= rowEnd && colStart <= colEnd)
    {
        // Print leftDown
        for (int i = rowStart; i <= rowEnd; i++)
        {
            cout << a[i][colStart] << ", ";
        }
        colStart++;

        // Print bottomRight
        for (int i = colStart; i <= colEnd; i++)
        {
            cout << a[rowEnd][i] << ", ";
        }
        rowEnd--;

        // Print rightTop
        if(rowEnd > rowStart)
        {
            for (int i = rowEnd; i >= rowStart; i--)
            {
                cout << a[i][colEnd] << ", ";
            }
            colEnd--;
        }

        // Print topRight
        if(colEnd > colStart)
        {
            for (int i = colEnd; i >= colStart; i--)
            {
                cout << a[rowStart][i] << ", ";
            }
            rowStart++;
        }
    };  

    return 0;
}