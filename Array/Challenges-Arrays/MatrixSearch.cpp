#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int key;
    cin >> key;
    
    int i = 0, j = m - 1;
    bool presence = false;
    while(i < n && j > -1)
    {
        if(a[i][j] == key)
        {
            presence = true;
            break;
        }
        else if(a[i][j] > key)
            j--;
        else
            i++;
    }

    if(presence)
        cout << 1;
    else 
        cout << 0;
    return 0;
}