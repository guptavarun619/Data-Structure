#include<iostream>
using namespace std;
// Bitonic array can be described as monotically increasing followed by monotonically decreasing array
// NOTE: An array is considered to be monotonically increasing iff a[i] < a[i+1] always
// same goes for monotincally decreasing in decreasing fashion
// And this results in ONLY ONE PEAK ELEMENT in the array
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

    int s = 0, e = n - 1, mid;

    while(s<=e)
    {
        mid = s + ((e - s) / 2);
        if(mid != 0 && mid < n - 1)
        {
            if(a[mid] < a[mid - 1])
                e = mid - 1;
            else if(a[mid] < a[mid + 1])
                s = mid + 1;
            else
                break;
        }
        else
            break;
    }
    cout << "Maximum valued element(peak) for the bitonic array is : " << a[mid] << endl;
    return 0;
}