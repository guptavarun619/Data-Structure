#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    // Parameters for container will be
    // starting of container, middle of container, end of container
    rotate(arr, arr + 2, arr + n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Next permutaion

    next_permutation(arr, arr + n);
    for(int x:arr){
        cout << x << " ";
    }
    cout << endl;

    next_permutation(arr, arr + n);
    for(int x:arr){
        cout << x << " ";
    }
    cout << endl;

    int arr2[] = {1, 2, 3, 4, 5};
    int size  = sizeof(arr2) / sizeof(int);
    reverse(arr2, arr2+size);
    for(int x : arr2)
        cout << x << " ";
    cout << endl;

    return 0;
}