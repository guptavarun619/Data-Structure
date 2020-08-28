#include<iostream>
using namespace std;

int lastOcc(int a[], int n, int key)
{
    if(n < 0)
        return -1;
    if(a[n-1] == key)
        return n-1;    
    int i = lastOcc(a, n-1, key);

    return i;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, key;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> key;

    int ans = lastOcc(a, n, key);
    if(ans == -1)
        cout << key << " element not found." << endl;
    else
        cout << key << " element found at " << ans << " index." << endl;

    return 0;
}