#include<iostream>
using namespace std;
// Nearly sorted array refers to an array in which and element 
// which is supposed to be at ith position can placed at
// (i-1)th position (i+1)th position or ith 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    // cout << endl;

    int key;
    cin >> key;

    int s = 0, e = n - 1;
    int mid;
    int index = -1;
    while (s <= e)
    {
        mid = s + ((e - s)/2);
        // cout << a[prev] << " " << a[mid] << " " << a[next] << endl;
        if(a[mid] == key)
        {
            index = mid;
            break;
        }
        else if(mid > 0 && a[mid - 1] == key)
        {
            index = mid - 1;
            break;
        }
        else if(mid < n - 1 && a[mid + 1] == key)
        {
            index = mid + 1;
            break;
        }
        else if(a[mid] < key)
            s = mid + 2;
        else
            e = mid - 2;
    }
    
    if (index != -1)    
        cout << key << " is found at index : " << index << endl;
    else
        cout << key << " element not found" << endl;

    return 0;
}