#include<iostream>
using namespace std;

int binary_search(int a[], int s, int e, int key)
{
    int mid;
    while (s <= e)
    {
        mid = s + ((e - s) / 2);
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            s = mid + 1;
        else 
            e = mid - 1;
    }
    return -1;
}

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

    // Finding minimum element to know the number times it's been rotated
    int s = 0, e = n - 1, mid;
    while(s <= e)
    {
        mid = s + ((e - s) / 2);
        if (mid != 0 && mid < n - 1)
        {
            if (a[mid] > a[mid - 1])
                s = mid + 1;
            else if (a[mid] < a[mid + 1])
                e = mid - 1;
            else
                break;
        }
    }

    if (mid == 0)
    {
        int ans = binary_search(a, 0, n - 1, key);
        if (ans != -1)
            cout << key << " found at index : " << ans << endl;
        else
            cout << key << " not found in the array." << endl;
    }
    else
    {
        int left = binary_search(a, 0, mid - 1, key);
        int right = binary_search(a, mid, n - 1, key);
        if(left != -1)
            cout << key << " found at index : " << left << endl;
        else if (right != -1)
            cout << key << " found at index : " << right << endl;
        else 
            cout << key << " not found in the array." << endl;
    }

    return 0;
}