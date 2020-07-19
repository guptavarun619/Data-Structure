#include<iostream>
#include<climits>
#include<algorithm>

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
    // {
        cin >> a[i];
    //     cout << a[i] << " ";
    // }

    // Insertion Sort Algorithm
    for (int i = 1; i < n; i++)
    {
        int tmp = a[i], pos = i;      
        while(pos > 0 && a[pos-1] > tmp)
        {
            a[pos] = a[pos-1];
            pos--; 
        }
        a[pos] = tmp;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    return 0;
}