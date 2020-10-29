#include<iostream>
using namespace std;

void printWave(int a[][10], int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        if(j%2 == 0) // topDown
        {
            for (int i = 0; i < m; i++)
            {
                cout << a[i][j] << ", ";
            }
            
        }
        else // bottomUp
        {
            for (int i = m - 1; i >= 0; i--)
            {
                cout << a[i][j] << ", ";
            }
        }
    }
    cout << "END";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int m, n, a[10][10];
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    printWave(a, m, n);

    return 0;
}