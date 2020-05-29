#include<iostream>
using namespace std;
// Find the key element in an infinite sorted array
// NOTE: please provide the key(input) in such a manner 
// so that for it upper limit does not exceed the provided array
// Since you don't get to insert actual infinite array
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

    int key;
    cin >> key;
    
    int s = 0, e = 1, mid;
    while(a[e] < key)
    {
        s = e;
        e = e * 2;
    };

    bool found = false;
    while (s <= e)
    {
        mid = s + ((e - s)/2);
        if (a[mid] == key)
        {
            found = true;
            break;
        }
        else if (a[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    if(found)
        cout << key << " found at index " << mid << endl; 
    else
        cout << key << " can't not be found in this infinte sorted array" << endl;


    return 0;
}