#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    char a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(s >= k)
            {
                if (a[i][j] == '#')
                    break;
                else if (a[i][j] == '*')
                    s += 5;
                else if (a[i][j] == '.')
                    s -= 2;
                if(j != m - 1)
                    s -= 1;
            }
            else
            {
                cout << "No";
                return 0;
            }
        }
    }

    if (s >= k)
        cout << "Yes\n" << s;
    else
        cout << "No";
    
    return 0;
}