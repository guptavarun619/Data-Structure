#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    // Search a key element in sorted array
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);
    int key = 8;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int s = 0, e = n - 1;
    int mid;
    bool found = false;

    while(s <= e)
    {
        mid = (e + s)/2;
        if(arr[mid] == key)
        {
            found = true;
            break;
        }
        else if(arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }; 

    if (found)
        cout << key << " found at : " << mid << " index" << endl;
    else
        cout << key << " not found" << endl;

    return 0;
}