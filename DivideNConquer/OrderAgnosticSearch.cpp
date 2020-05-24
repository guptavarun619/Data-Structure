#include<iostream>
using namespace std;

// The input array is sorted but it is not specified if the the order is ascending or descending

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

    int key;
    cin >> key;

    bool asc = true;
    if (n > 1)
        asc = a[0] < a[1] ? true : false;
    // if 1st element is smaller than second, definately the array is arranged
    // in ascending order else in descending order

    int s = 0, e = n - 1, mid;
    int ans = -1;
    while(s <= e)
    {
        mid = s + (e-s)/2;
        if(a[mid] == key)
        {
            ans = mid;
            break;
        }
        else if (key < a[mid])
        {
            if(asc)
                e = mid - 1;
            else
                s = mid + 1;
        }
        else
        {
            if(asc)
                s = mid + 1;
            else 
                e = mid - 1;
        }
    };

    if(ans == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element " << key << " found at : " << ans << endl;

    return 0;
}