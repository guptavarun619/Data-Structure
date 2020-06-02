#include<iostream>
using namespace std;
// Allocate Pages of Books
bool allocate(int a[], int n, int k, int max)
{
    int students = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if(sum > max)
        {
            students++;
            sum = a[i];
        }
        if(students > k)
            return false;
    }
    return true;
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
        int n;
        cin >> n;

        int k;
        cin >> k;
        
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];


        int s, e, mid;
        if (a[0] < a[n-1])
        {
            s = a[n-1];
            for (int i = 0; i < n - 2; i++)
                e += a[i];
        }
        else
        {
            s = a[0];
            for (int i = 1; i < n - 1; i++)
                e += a[i];
        }
        int ans = -1;
        while(s <= e)
        {
            mid = s + ((e - s) / 2);
            if(allocate(a, n, k, mid))
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