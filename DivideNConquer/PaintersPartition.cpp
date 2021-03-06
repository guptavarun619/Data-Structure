#include<iostream>
#include<climits>
#include<algorithm>
#define int long long
using namespace std;

bool check(int a[], int n, int k, int time)
{
    int count = 1, tmp = time;
    for (int i = 0; i < n; i++)
    {
        if(a[i] <= tmp)
            tmp -= a[i];
        else
        {
            count++;
            tmp = time;
            if(a[i] > tmp)
                return false;
            else
                tmp -= a[i];
        }
    }
    if(count <= k)
        return true;
    else
        return false;
    
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, k, t;
    cin >> n >> k >> t;
    // n => no of boards,
    // k => no of painters,
    // t => time taken to pain 1 unit of board by 1 painter 
    int a[n], mx = LONG_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    int ans = -1, s = mx, e = sum;
    while(s <= e)
    {
        int mid = s + (e-s)/2;
        if(check(a, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;            
    }
    cout << (ans*t)%10000003;
    return 0;
}