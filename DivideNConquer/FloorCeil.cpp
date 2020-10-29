#include<iostream>
using namespace std;
// Floor element refers to the greatest element but less than given key
// Ceil element refers to the smallest element but greater/equal to given key

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

    int s = 0, e = n - 1, mid;
    int floor;

    while (s <= e)
    {
        mid = s + ((e - s)/2);
        if (a[mid] < key)
        {
            floor = a[mid];
            s = mid + 1;
        }
        else 
            e = mid - 1;
    }

    cout << floor << " is the floor of " << key << endl;

    int ceil;
    s = 0;
    e = n - 1;

    while (s <= e)
    {
        mid = s + ((e - s)/ 2);
        if (a[mid] == key)
        {
            ceil = a[mid];
            break;
        }
        else if (a[mid] > key)
        {
            ceil = a[mid];
            e = mid - 1;
        }
        else 
            s = mid + 1;
    }    
    
    cout << ceil << " is the ceil of " << key << endl;

    return 0;
}