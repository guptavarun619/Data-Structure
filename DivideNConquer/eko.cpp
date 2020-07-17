#include<iostream>
#include<climits>
#define int long long
using namespace std;

bool check(int a[], int n, int wood, int height)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] > height)
            sum += a[i] - height;
        if(sum >= wood)
            return true;
    }
    
    return false;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;

    int *a = new int[n], mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    } 

    int s = 0, e = mx, ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s)/2;
        if(check(a, n, m, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    if(ans != -1)
        cout << ans;
    else
        cout << -1;
    return 0;
}