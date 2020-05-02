#include<iostream>
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
        int a[n];
        int temp;
        int maxSum = 0, tempSum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            tempSum += a[i];
            if (tempSum < 0)
                tempSum = 0;
            maxSum = max(maxSum, tempSum);
        }
        cout << maxSum << endl;
    }
    return 0;
}