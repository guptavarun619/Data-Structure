#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int> a, pair<string,int> b)
{
    if(a.second > b.second)
        return true;
    else if(a.second == b.second)
    {
        if(a.first < b.first)
            return true;
    }
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int x, n;
    cin >> x >> n;

    vector< pair<string, int> > a;
    for (int i=0; i<n; i++)
    {
        cin.ignore();
        string s;
        cin >> s;
        int t;
        cin >> t;
        a.emplace_back(s,t);
    }

    sort(a.begin(), a.end(), compare);

    for (int i=0; i<n; i++)
    {
        if(a[i].second >= x)
            cout << a[i].first << " " << a[i].second <<endl;
    }
    cout <<endl;

    return 0;
}