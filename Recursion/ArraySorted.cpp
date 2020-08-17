// check if the array is sorted or not using recursion
#include<iostream>
using namespace std;

bool isSorted(int a[], int n)
{
    // base case
    if(n <= 1)
        return true;
    // recursive case
    if (a[0] < a[1] && isSorted(a+1, n-1))
        return true;
    else
        return false;
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
    if(isSorted(a, n))
        cout << "Array is sorted" << endl;
    else
        cout << "Array is not sorted" << endl;
        
    return 0;
}