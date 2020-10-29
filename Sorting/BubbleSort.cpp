#include <bits/stdc++.h>
using namespace std;

void cpSetup() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int32_t main() {
    cpSetup();

    int n;
    cin >> n;
    int *a;
    a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    // Bubble Sort Algorithm
    
    for(int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
        cout << i+1 << " pass : ";
        for(int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    cout << "Sorted array is : ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}