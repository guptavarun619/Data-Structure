#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, x;
        cin >> n >> k;
        // cout << n << " " << k << " ";
        int s = 1, e = n, mid, ans = -1;
        while(s <= e)
        {
            mid = s + (e-s)/2;
            if(pow(mid,k) <= n)
            {
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}