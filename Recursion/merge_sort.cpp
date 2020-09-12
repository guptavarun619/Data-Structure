#include<iostream>
using namespace std;

void merge(int a[], int s, int e)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];
    while(i <= mid && j <= e)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];      
    }
    // incase any of the small array is exhausted
    while(i <= mid)
        temp[k++] = a[i++];
    while(j <= e)
        temp[k++] = a[j++];

    // copy all elements to orignal array
    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
}

void merge_sort(int a[], int s, int e)
{
    // base case - single element
    if(s >= e)
        return;
    // divide
    int mid = (s+e)/2;

    // sort 
    merge_sort(a, s, mid);
    merge_sort(a, mid + 1, e);

    // merge
    merge(a, s, e);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    // #endif
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    cout << endl;

    merge_sort(a, 0, n-1);

    cout << "Sorted array is " << endl;    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}