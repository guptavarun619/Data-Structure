#include<iostream>
using namespace std;
// Find how manytimes the sorted-array has been rotated
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

    int index = -1, min;
    int s = 0, e = n - 1, mid;
    while(s <= e)
    {
        mid = s + ((e - s)/2);
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if(a[mid] < a[next] && a[mid] < a[prev])
        {
            min = a[mid];
            index = mid;
            break;
        }
        else if(a[mid] < a[0])
            e = mid - 1;
        else 
            s = mid + 1;
    }
    cout << "Minimum valued element is " << min << endl;
    cout << "No. of times the array is rotated is " << index << endl;
    // Index of the smallest valued element gives the number of times a sorted array has been rotated
    return 0;
}