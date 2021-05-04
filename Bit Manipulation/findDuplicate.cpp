#include <bits/stdc++.h>
using namespace std;

// Sample input:
// 6
// 1 3 3 4 5 6
// 1 2 3 4 5 6 

// Expected output : 2 3

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif  

    int n;
    cin >> n;
    n *= 2;
    int a[n], xr = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xr ^= a[i];
        // cout << xr << endl;
    } 

    // cout <<  xr;

    int rsb = xr & ~(xr - 1);

    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] & rsb)
            x ^= a[i];
        else 
            y ^= a[i];
    }

    // Here we'll get the repeating number
    for (int i = 0; i < n; i++) {
        if(y == a[i]) {
            swap(x,y);
            break;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}