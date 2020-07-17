#include<iostream>
#include<climits>
#include<algorithm>
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

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int k, n;
    cin >> k >> n;
    int a[n], mx = INT_MIN, sum = 0;
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
    cout << ans;
    return 0;
}