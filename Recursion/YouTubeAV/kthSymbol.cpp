#include<bits/stdc++.h>
using namespace std;
// Grammer is like :-
// 0
// 01
// 0110
// 01101001

int grammer(int n, int k)
{
    if(n == 1 && k == 1)
        return 0;
    
    int mid = pow(2,n-1)/2;
    if(k <= mid)
        return grammer(n-1, k);
    else
        return !grammer(n-1, k-mid);
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int a, b;
    cin >> a >> b;

    cout << grammer(a, b) << endl;
    // cout << 1 << " " << !1 << endl;
    
    return 0;
}