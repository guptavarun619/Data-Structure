#include<iostream>
#include<algorithm>
using namespace std;

// Comparator function for decreasing fasion
bool compare(int a, int b)
{
    return a > b;
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
    
    // Sorting in ascending order
    sort(a, a+n);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;    

    // Sorting in descending order
    sort(a, a+n, compare);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;    

    return 0;
}