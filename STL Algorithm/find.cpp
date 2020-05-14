#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr)/sizeof(int); // Array lenght

    // Search in any container

    int key = 3;
    auto it = find(arr, arr+n, key);
    cout << "Address " << it << endl;
    cout << "Key " << *it << endl;

    int index = it - arr;
    cout << "Position " << index << endl;

    int key2 = 100;
    it = find(arr, arr + n, key2);
    index = it - arr;
    if(index == n){
        cout << key2 << " not present" << endl;
    } else {
        cout << "Present at index " << index << endl;
    }


    return 0;
}