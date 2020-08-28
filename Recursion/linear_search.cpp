#include<iostream>
using namespace std;

void allOcc(int a[], int i, int n, int key)
{
    if(i == n)
        return;
    if(a[i] == key)
        cout << key << " is present at index " << i << endl;
    allOcc(a, i+1, n, key);
}

int firstOcc(int a[], int n, int key)
{
    if(n == 0)
        return -1;
    
    if(a[0] == key)
        return 0;
    
    int i = firstOcc(a+1, n-1, key);

    if(i == -1)
        return -1;
    
    return i+1;
}

int lastOcc(int a[], int n, int key)
{
    if(n < 0)
        return -1;
    if(a[n-1] == key)
        return n-1;    
    int i = lastOcc(a, n-1, key);

    return i;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, key, first, last;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> key;

    first = firstOcc(arr, n, key);
    last = lastOcc(arr, n, key);
    allOcc(arr, 0, n, key);

    if(first != -1)
        cout << "First occurence of " << key << " is at index : " << first << endl;
    else
        cout << "Element " << key << " not found" << endl;

    if(last != -1)
        cout << "Last occurence of " << key << " is at index : " << last << endl;
    else
        cout << "Element " << key << " not found" << endl;

    return 0;
}