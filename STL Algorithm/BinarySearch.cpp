#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    // sorted array required
    int arr[] = {1,2,3,4,4,5,6,7};
    int n = sizeof(arr) / sizeof(int);

    int key = 12;

    bool present = binary_search(arr, arr+n, key);
    if (present) {
        cout << "Element is present" << endl;
    } 
    else 
        cout << "Element is not present" << endl;
    
    // To get the index of the key element
    // lower_bound(s, e, key) and upper_bound(s, e, key);
    // key is given 4 as default in code
    auto lb = lower_bound(arr, arr+n, 4); // gives first element<= key 
    cout << "Lower bound Index : " << lb - arr << endl;


    auto ub = upper_bound(arr, arr+n, 4); // gives first element > key
    cout << "Upper bound Index : " << ub - arr << endl;

    cout << "Frequency of '4' is : " << ub -lb << endl;

    return 0;
}