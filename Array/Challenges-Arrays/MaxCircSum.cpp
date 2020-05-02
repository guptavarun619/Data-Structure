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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int maxSum = 0;
        for (int j = 0; j < n; j++)
        {
            int tempSum = 0;
            for (int i = j; i < n+j; i++)
            {
                tempSum += a[i%n];
                if(tempSum < 0)
                    tempSum = 0;
                maxSum = max(maxSum, tempSum);
            }
        }
        
        
        cout << maxSum << endl;        
    }
    return 0;
}