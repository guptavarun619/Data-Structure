#include<iostream>
using namespace std;
// Given an unsorted array, return the Peak element(s) present in the array
// Peak element(s) - which are greater than it's neighbour elements
// Returing index of either peak element(multiple) array is acceptable. 
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
    int ans = -1;
    while(s <= e)
    {
        mid = s + ((e - s) / 2);

        if (mid > 0 && mid < n - 1)
        {
            if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
            {
                ans = mid;
                break;
            }
            else if(a[mid - 1] > a[mid])
                e = mid - 1;
            else 
                s = mid + 1;
        }
        else if (mid == 0)
        {
            if (a[mid] > a[mid + 1])
            {
                ans = mid;
                break;
            }   
        }
        else 
        {
            if (a[mid] > a[mid - 1])
            {
                ans = mid;
                break;
            }
        }
    }

    if (ans != -1)
        cout << "The peak element index is at : " << ans << endl;
    else 
        cout << "No peak element found";

    return 0;
}