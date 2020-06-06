#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        int leftInc[n] = {0};
        leftInc[0] = 1;
        // evaluating maximum increasing subarray size from left 
        for (int i = 1; i < n; i++)
        {
            if(a[i] >= a[i - 1])
                leftInc[i] = leftInc[i - 1] + 1;
            else
                leftInc[i] = 1;
        }

        int rightInc[n] = {0};
        rightInc[n-1] = 1;
        // evaluating maximum increasing subarray size from left 
        for (int i = n-2; i >= 0; i--)
        {
            if(a[i] >= a[i + 1])
                rightInc[i] = rightInc[i + 1] + 1;
            else
                rightInc[i] = 1;
        }
        
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(leftInc[i] + rightInc[i], ans);
        }
        cout << ans - 1 << endl;
    };
    return 0;
}