#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int **arr;
    int r, c;
    cin >> r >> c;

    // Create array of only row pointers
    arr = new int*[r];
    // Creating column array for each row
    for(int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
    }

    for(int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}