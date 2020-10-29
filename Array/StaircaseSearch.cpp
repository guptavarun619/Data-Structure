#include<iostream>
using namespace std;
// Searching in row & col wise in Sorted array
void search(int a[][100], int r, int c, int key)
{
    int i = 0, j = c - 1;
    while(a[i][j] != key)
    {
        if(a[i][j] < key)
            i++;
        else if(a[i][j] > key)
            j--;
        if(i > r - 1 || j < 0)
        {
            cout << "Element not found!" << endl;
            break;
        }
    }
    if(a[i][j] == key)
        cout << "Element " << key << " found at : " << i << "," << j << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int r, c, a[100][100], key;
    cin >> r >> c >> key;
    cout << "Initail Array : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    search(a, r, c, key);
}