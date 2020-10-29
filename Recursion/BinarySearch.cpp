// Implement Binary Search using recursion
#include<iostream>
using namespace std;

int bin_search(int a[], int s, int e, int key)
{
    if(s <= e)
    {
        int mid = s + (e-s) / 2;
        if(a[mid] == key)
            return mid;
        else if(a[mid] > key)
            return bin_search(a, s, mid - 1, key);
        else 
            return bin_search(a, mid + 1, e, key);
    }
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, key;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> key;
    int found = bin_search(a, 0, n-1, key);
    if(found == -1)
        cout << "Key element not found" << endl;
    else
        cout << key << " found at index " << found << endl;
    return 0;
}