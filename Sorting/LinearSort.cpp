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
    int s = 0, m = 0, e = n-1;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while(m <= e)
    {
        if(a[m] == 0)
        {
            swap(a[m], a[s]);
            m++;
            s++;
        }
        else if(a[m] == 1)
        {
            m++;
        }
        else
        {
            swap(a[e], a[m]);
            e--;
        }
        
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
        
    }

    return 0;
}