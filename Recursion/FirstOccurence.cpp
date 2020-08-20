#include<iostream>
using namespace std;

int firstOcc(int a[], int n, int key)
{
    if(n == 0)
        return -1;
    
    if(a[0] == key)
        return 0;
    
    int i = firstOcc(a+1, n-1, key);

    if(i == -1)
        return -1;
    
    return i+1;


}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, key;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> key;

    int ans = firstOcc(arr, n, key);

    if(ans != -1)
        cout << "First occurence of " << key << " is at index : " << ans << endl;
    else
        cout << "Element " << key << " not found" << endl;

    return 0;
}