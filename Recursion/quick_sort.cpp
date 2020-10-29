#include<iostream>
using namespace std;

// Bestcase complexity - O(NlogN)
// Worstcase complexity - O(N^2)
int partition(int a[], int s, int e)
{
    int i = s-1;
    int j = s;

    int pivot = a[e];
    for( ;j <= e-1; j++)
    {
        if(a[j] < pivot)
        {
            // here merge the smaller element into the region-1(left)
            i++;
            swap(a[i], a[j]);
        }
    }

    // place the pivot element in the correct index
    swap(a[i+1], a[e]);

    return i+1;
}

void quick_sort(int a[], int s, int e)
{
    // base case
    if(s >= e)
        return;

    // recursive case
    int p = partition(a, s, e);
    // left part
    quick_sort(a, s, p-1);
    // right part
    quick_sort(a, p+1, e);
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
    {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    // cout << endl;

    quick_sort(a, 0, n-1);

    cout << "Sorted array is " << endl;    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    
    return 0;
}