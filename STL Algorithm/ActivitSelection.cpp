#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        pair<int, int> p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].first >> p[i].second;

        int temp = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            if(temp <= p[i].first)
            {
                // cout << temp << endl;
                temp = p[i].second;
                count++;
            }
            else 
                continue;
        }
        cout << count;
    };
    return 0;
}