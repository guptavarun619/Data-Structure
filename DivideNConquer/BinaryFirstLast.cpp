// Find the First/ Last occurence of the key element 
// Using Binary Search (obviously in sorted array)

#include<iostream>
using namespace std;

int first_occurence(int a[], int n, int key)
{
    int s = 0, e = n - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (a[mid] < key)
            s = mid + 1;
        else 
            e = mid + 1;
    }
    return ans;
}

int last_occurence(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s+e) / 2;
        if(arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10, 12, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 8;

    // First and Last occurence of of a key in sorted array
    cout << "First occurence : " << first_occurence(arr, n, key) << endl;
    cout << "Last occurence : " << last_occurence(arr, n, key) << endl;

    return 0;
}