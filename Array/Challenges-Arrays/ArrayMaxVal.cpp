#include<iostream>
#include<climits>
using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;

    long long a[n];
    long long maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }

    cout << maxVal;

    return 0;
}