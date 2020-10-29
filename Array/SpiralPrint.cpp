#include<iostream>
using namespace std;

// spiral Print: Tranverse in given pattern
// 1\/ 2<< 3/\
// 4\/ 5\/ 6/\
// 7>> 8>> 9/\

void printSpiral(int a[][10], int m, int n)
{
    int startRow = 0;
    int startCol = 0;
    int endRow = m - 1;
    int endCol = n - 1;

    while(startRow <= endRow and startRow <= endCol)
    {
        // First Row
        for (int i = startCol; i <= endCol; i++)
        {
            cout << a[startRow][i] << " ";
        }
        startRow++;

        // End Column;
        for (int i = startRow; i <= endRow; i++)
        {
            cout << a[i][endCol] << " ";
        }
        endCol--;
        
        // End Row
        if(endRow > startRow) 
        {
            for (int i = endCol; i >= startCol; i--)
            {
                cout << a[endRow][i] << " ";
            }
            endRow--;
        }
        // First Column;
        if(endCol > startCol)
        {
            for (int i = endRow; i >= startRow; i--)
            {
                cout << a[i][startCol] << " ";
            }
            startCol++;
        }
    }
    cout << endl;
}

int main()
{
    int a[10][10];
    int count = 1;
    int m, n;
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
    printSpiral(a, m, n);
    return 0;
}
