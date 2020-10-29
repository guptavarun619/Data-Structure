#include<iostream>
#include<climits>
using namespace std;

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

    int min = INT_MAX;
    int index = -1;
    int s = 0, e = n-1, mid;
    while(s <= e)
    {
        mid = s + ((e-s)/2);
        if (a[mid] < a[s])
        {
            if(a[mid] < min)
            {
                min = a[mid];
                index = mid;
                e = mid - 1;
            }
            else   
                s = mid + 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << "Minimun valued element is " << min << endl;
    cout << "Minimum valued index is " << index << endl;
    return 0;
}