#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, water = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int left[n] = { 0 }, right[n] = { 0 };
    
    // Left-max array
    int temp = 0;
    for (int i = 1; i < n; i++)
    {
        left[i] = max(a[i-1],temp);
        temp = left[i];
    }

    // Right-max array
    temp = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(a[i+1],temp);
        temp = right[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - a[i] > 0 ? min(left[i], right[i]) - a[i] : 0;
    }
    
    cout << water << endl;
    
    return 0;
}