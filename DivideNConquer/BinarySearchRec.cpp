#include<iostream>
using namespace std;

int binary_search(int a[], int key, int s, int e)
{
    int ans = -1;
    if (s <= e)
    {
        int mid = (s + e) / 2;
        if(a[mid] == key)
            return mid;
        else if (a[mid] < key)
            ans = binary_search(a, key, mid + 1, e);
        else
            ans = binary_search(a, key, s, mid - 1);
    }
     
    return  ans;        
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout << arr[i] << " ";
    }   
    // cout << endl;

    int k;
    cin >> k;

    int index = binary_search(arr, k, 0, n-1);
    if (index != -1)
        cout << "Element " << k << " found at index : " << index << endl;
    else 
        cout << "Element not found" << endl;
    return 0;
}