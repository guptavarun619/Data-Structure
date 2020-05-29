#include<iostream>
using namespace std;
// Provided an infinite sorted binary array {0, 0 , 0, 1 ,1 ,1...}
// Find the index of first "1"
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int s = 0, e = 1, mid;
    while(a[e] != 1)
    {
        s = e;
        e = e * 2;
    }
    cout << s << " " << e << endl;

    int ans = -1;
    while (s<= e)
    {
        mid = s + ((e - s) / 2);
        if(a[mid] == 1)
        {
            ans = mid;
            e = mid - 1;
        }
        else 
            s = mid + 1;
    }

    cout << "The first index of 1 is at " << ans;
    return 0;
}