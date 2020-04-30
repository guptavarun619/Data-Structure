#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int a[100][100], key, row, col;
    cin >> row >> col;
    // NOTE THE ARRAY SHOULD BE SORTED ROW AND COL WISE
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }        
    }

    
    
    return 0;
}