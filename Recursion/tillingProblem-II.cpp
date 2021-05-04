#include <bits/stdc++.h>
using namespace std;

int placeTile(int n, int m) {
    // base case 
    if(n < m)
        return n;
    // rec case
    // we have two ways to place the tile 
    return placeTile(n-1, m) + placeTile(n-m, m);
    // first placed vertically and then horizontally
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif    
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << placeTile(n, m) << endl;
    }
    return 0;
}