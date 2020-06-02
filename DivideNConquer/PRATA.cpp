#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int prata(int rank, int time)
{
    int n = 0, i = 1;
    // cout << rank*i << " " << time << endl;
    while(rank*i <= time)
    {
        n++;
        time = time - rank*i;
        i++;
    }
    // cout << n << endl;
    return n;
}

bool delivery(int a[], int c, int n, int time)
{
    int totalPrata = 0;
    for (int i = 0; i < c; i++)
    {   
        // cout << totalPrata << " " << a[i] << endl;
        totalPrata += prata(a[i], time);
        if (totalPrata >= n)
            return true;
    }
    return false;    
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n, c; 
        cin >> n >> c;

        int a[c], x = INT_MIN;
        for (int i = 0; i < c; i++)
        {
            cin >> a[i];
            x = max(a[i], x);
        }

        int ans = -1;
        int s = 0, e = 0;
        for (int i = 1; i <= n; i++)
        {
            e += x*i;
        }
        
        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            // cout << "mid "<< mid << endl ;
            if(delivery(a, c, n, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }

        cout << ans << endl;
    
    }
    return 0;
}