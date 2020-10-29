#include<iostream>
using namespace std;

int search(int a[], int n, int key)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e-s) / 2;
        if(a[mid] == key)
            return mid;
        else if (a[s] <= a[mid])
        {
            // 2 cases -> element lies on the left or the right of the mid
            if (key >= a[s] && key <= a[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else
        {
            // 2 cases -> element lies on the left or the right of the mid
            if(a[mid] <= key && key <= a[e])
                s = mid + 1;
            else
                e = mid - 1; 
        }
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

    cout << search(a, n, key);

    return 0;
}