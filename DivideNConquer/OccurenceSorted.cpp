#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n = 1;
    cin >> n;

    int a[1000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    int key;
    cin >> key;
    
    // Finding first occurence of the key element
    int s = 0, e = n - 1, mid;
    int first_index = -1;
    while(s <= e)
    {
        mid = s + (e - s)/2;
        if(a[mid] == key)
        {
            first_index = mid;
            e = mid - 1;
        }
        else if (key < a[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }

    // Finding last occurence of the key element
    s = 0;
    e = n - 1;
    int last_index = -1;
    while(s <= e)
    {
        mid = s + (e - s)/2;
        if(a[mid] == key)
        {
            last_index = mid;
            s = mid + 1;
        }
        else if (key < a[mid])
            e = mid - 1;
        else 
            s = mid + 1;
    }

    if(first_index == -1 && last_index == -1)
        cout << key << " is not present in the array" << endl;
    else
    {
        cout << key << " is present " << last_index - first_index + 1 << " times" << endl;
    }

    return 0;
}