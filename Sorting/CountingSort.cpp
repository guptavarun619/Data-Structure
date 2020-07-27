#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    int a[n], mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int count[mx+1] = {0};
    // evaluating count array
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    // maipulating count array to get index
    for (int i = 1; i < mx+1; i++)
        count[i] = count[i] + count[i-1];

    // creating final sorted array
    int ans[n]; 
    for (int i = 0; i < n; i++)
    {
        ans[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    
    // final output
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    
    

    
    return 0;
}