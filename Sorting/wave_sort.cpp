#include <bits/stdc++.h>
using namespace std;

// Problem Statement - Sort the elements in a wave form S-B-S-B-S OR B-S-B-S-B
// Above B => Bigger element S => smaller element

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif    
    
    int a[] = {1, 3, 4, 2, 7, 4};
    int n = sizeof(a) / sizeof(int);
    
    for (int i=0; i<n; i+=2) {
        // Prev element comparision
        if(i!=0 && a[i] < a[i-1]) {
            swap(a[i], a[i-1]);
        }

        // Next element 
        if(i!= n-1 && a[i] < a[i+1]) {
            swap(a[i], a[i+1]);
        }
    }

    // Print array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}