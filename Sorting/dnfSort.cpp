#include <bits/stdc++.h>
using namespace std;

// Problem Statement - sort array of 0s 1s 2s

void dnf_sort(int a[], int n) {
    int i = 0, j = 0, k = n-1;
    while(j <= k) {
        if(a[j] == 0) {
            swap(a[i], a[j]);
            i++; j++;
        }
        if(a[j] == 1)  
            j++;
        if(a[j] == 2) {
            swap(a[j], a[k]);
            k--;
        }

    }
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif    
    int a[] = {2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 2, 0};
    int n = sizeof(a) / sizeof(int);

    dnf_sort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}