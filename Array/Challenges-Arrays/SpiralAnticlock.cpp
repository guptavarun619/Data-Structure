#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int rs = 0, re = m - 1, cs = 0, ce = n - 1;
    while(rs <= re && cs <= ce)
    {
        // top-down (left)
        for (int i = rs; i <= re; i++)
        {
            cout << a[i][cs] << ", ";
        }
        cs++;

        // left - right (bottom)
        for (int i = cs; i <= ce; i++)
        {
            cout << a[re][i] << ", ";
        }
        re--;

        // bottom - up (right)
        if(rs < re)
        {
            for (int i = re; i >= rs; i--)
            {
                cout << a[i][ce] << ", ";
            }
            ce--;
        }

        // left - right (top)
        if(cs < ce)
        {
            for (int i = ce; i >= cs; i--)
            {
                cout << a[rs][i] << ", ";
            }
            rs++;
        }
    }
    cout << "END" << endl;

    return 0;
}