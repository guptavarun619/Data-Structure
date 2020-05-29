#include<iostream>
using namespace std;
// Provided the key, find it's next character in the sorted array

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    int n;
    cin >> n;

    char a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    char key;
    cin >> key;

    int s = 0, e = n - 1, mid;
    int ans = -1;
    while(s <= e)
    {
        mid = s + ((e - s)/2);
        if(a[mid] > key)
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    if (ans != -1)
        cout << a[ans] << " is the next char available to " << key << endl;
    else
        cout << "No next character found in the sorted array" << endl;

    return 0;
}