#include<bits/stdc++.h>
using namespace std;

int merge(int a[], int s, int e)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[100];

    int cnt = 0;//cross inversions

    while(i<=mid and j<=e)
    {
        if(a[i] < a[j])
        {
            temp[k] == a[i];
            k++;
            i++;
        }
        else
        {
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }

    // fill the array if some elemetns are left in one of the arrays
    while(i <= mid)
        temp[k++] = a[i++];
    while(j <= e)
        temp[k++] = a[j++];

    // Copy all the elemets back to array a
    for(int i = s; i <= e; i++)
        a[i] = temp[i];

    return cnt;
}

int inversion_count(int *a, int s, int e)
{
    // base case
    if(s >= e)
        return 0;
    
    // merge sort
    int mid = (s+e)/2, ans = 0;
    ans += inversion_count(a, s, mid);
    ans += inversion_count(a, mid+1, e);
    ans += merge(a,s,e); //no of cross inversion

    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    // int n;
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     // cout << a[i] << " ";
    // }
    // cout << endl;

    int arr[] = {1, 5, 2, 6, 3, 0};
    int n = sizeof(arr) / sizeof(int);

    cout << inversion_count(arr, 0, n-1) << endl;

    return 0;
}