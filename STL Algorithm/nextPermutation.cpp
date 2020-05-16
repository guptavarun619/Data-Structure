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
    while(t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        next_permutation(arr, arr+n);
        for (int  x : arr)
            cout << x << " ";
        cout << endl;
    };
    return 0;
}