#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    // Static  Allocation (Deallocated automatically)
    int b[100] = {0};
    cout << sizeof(b) <<" " << sizeof(b)/sizeof(int) << endl;

    // Dynamic Allocation (during run time)
    int n;
    cin >> n;
    int *a = new int[n]{0};
    cout << sizeof(a) << " " << sizeof(int) << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cout << a[i] << " ";
    }
    
    // Free up the space for array allocated dynamically
    delete [] a;

    return 0;
}