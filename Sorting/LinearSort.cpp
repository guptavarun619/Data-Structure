#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }

    for (auto i = m.begin(); i!=m.end(); i++)
    {
        for (int j = 0; j < i->second; j++)
            cout << i->first << endl;
    }

    return 0;
}