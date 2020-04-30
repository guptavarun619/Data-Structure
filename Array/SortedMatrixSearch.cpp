#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int a[100][100], key, row, col;
    cin >> row >> col >> key;
    // NOTE THE ARRAY SHOULD BE SORTED ROW AND COL WISE
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }        
    }

    int i = 0, j = col - 1;
    while(i < row  && col > 0)
    {
        if(a[i][j] < key)
            i++;
        else if(a[i][j] > key)
            j--;
        if(a[i][j] == key)
        {
            cout << "Element found at " << i << "," << j << endl;
            break;
        }
    }

    if(a[i][j] != key)
        cout << "Element not found!" << endl;
    
    return 0;
}