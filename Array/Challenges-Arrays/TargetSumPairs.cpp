#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, key, a[1000];
    cin >> n ;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }    

    cin >> key;

    sort(a, a+n);

    int i = 0, j = n - 1;
    vector< pair <int, int> > sumPair;
    while(i < j)
    {
        if(a[i]+a[j] == key)
        {
            sumPair.emplace_back(make_pair(a[i], a[j]));
            i++;
            j--;
        }
        else if(a[i] + a[j] < key)
            i++;
        else
            j--;
    };
    for (int i = 0; i < sumPair.size(); i++)
    {
        cout << sumPair[i].first << " and " << sumPair[i].second << endl;
    }
    return 0;
}