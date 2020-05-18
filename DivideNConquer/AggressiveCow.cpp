#include<iostream>
#include<algorithm>
using namespace std;

bool config(int a[],int n, int c, int dist)
{
    int lastCow = a[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if(a[i] - lastCow >= dist)
        {
            
            lastCow = a[i];
            count++;
            if(count == c)  
                return true;
        }
    }
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int t, n, c;
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr+n);

        int s = 0, e = arr[n-1] - arr[0];

        int ans = 0;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (config(arr, n, c, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else 
            {
                e = mid - 1;
            }
        }        
        cout << ans << endl;
    };
    return 0;
}