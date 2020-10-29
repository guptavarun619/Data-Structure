#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n)
{
    // base case - i.e. all passes are completed
    if(n == 1)
        return;
    
    // recurrence case - take the highest element to last
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] > a[i+1])
            swap(a[i], a[i+1]);
    }
    bubble_sort(a, n-1);
}

void bubble_sort_recursive(int a[], int i, int n)
{
    // base case 
    if(n == 1)
        return;

    if(i == n-1) // each pass completes here
        return bubble_sort_recursive(a, 0, n-1);
    
    if(a[i] > a[i+1])
        swap(a[i], a[i+1]);

    bubble_sort_recursive(a, i+1, n);
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

    // bubble_sort(a, n);
    bubble_sort_recursive(a, 0, n);

    cout << "Sorted array is " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}