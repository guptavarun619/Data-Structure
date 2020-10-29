#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    int *a;
    a = new int[n];
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    
    // Selection Sort Algorithm
    for (int i = 0; i < n-1; i++)
    {
        // cpm a[i] min from i+1 to n-1
        int mn = INT_MAX, min_index = i;
        for(int j = i; j < n; j++)
        {
            if(a[j] < mn)
            {
                mn = a[j];
                min_index = j;
            }
        }
        // if(a[i] > a[min_index])
        swap(a[i], a[min_index]);
    }

    // Sorted Array would be
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}