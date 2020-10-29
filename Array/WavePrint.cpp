#include<iostream>
using namespace std;

// Wave Print: Tranverse in given pattern
// 1|| 2/\ 3||
// 4|| 5|| 6||
// 7\/ 8|| 9\/

int main()
{
    int a[10][10];
    int count = 1;
    int n, m;
    cout << "Enter no of rows and cols : ";
    cin >> m >> n;
    cout << "Initial 2D Array : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = count++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < n; j++)
    {
        if(j%2 == 0) //Even Col - Top Down
        {
            for (int i = 0; i < m; i++)
            {
                cout << a[i][j] << " ";
            }
            // cout << endl;
        }
        else // Odd Col - Bottom Up
        {
            for (int i = m-1; i >= 0; i--)
            {
                cout << a[i][j] << " ";
            }
            // cout << endl;
        }
    }   
    
    return 0;
}