#include<iostream>
using namespace std;

void LUBound(int a[], int n, int key)
{
    int s = 0, e = n-1, mid, low = -1, up = -1;
    while(s <= e)
    {
        mid = s + (e-s)/2;
        if(a[mid] == key)
        {
            low = mid;
            e = mid - 1;
        }
        else if(a[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    s = 0;
    e = n-1;
    while(s <= e)
    {
        mid = s + (e-s)/2;
        if(a[mid] == key)
        {
            up = mid;
            s = mid + 1;
        }
        else if(a[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    cout << low << " " << up << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n, q;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int tmp;
        cin >> tmp;
        LUBound(a, n, tmp);
    }

    
    return 0;
}