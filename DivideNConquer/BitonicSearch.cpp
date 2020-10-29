#include<iostream>
using namespace std;

int binary_search(int a[], int s, int e, int key)
{
    while(s <= e)
    {
        int mid = s + ((e - s) / 2);
        if(a[mid] == key)
            return mid;
        else if (key < a[mid])
            e = mid - 1;
        else 
            s = mid + 1;
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

    // finding the peak of bitonic array
    int s = 0, e = n - 1, mid;
    int half = -1;
    while(s <= e)
    {
        mid = s + ((e - s)/ 2);
        if(mid != 0 && mid < n - 1)
        {
            if(a[mid] < a[mid - 1])
                e = mid - 1;
            else if(a[mid] < a[mid + 1])
                s = mid + 1;
            else 
            {
                half = mid;
                break;
            }
        }
    }
    // cout << half << endl; //peak of bitonic array

    int left = binary_search(a, 0, half, key);
    int right = binary_search(a, half+1, n, key);

    if(left != -1)
        cout << key << " element not found at index : " << left << endl;
    else if (right != -1)
        cout << key << " element not found at index : " << right << endl;
    else
        cout << key << " element not found in the bitonic array" << endl;
    
    return 0;
}