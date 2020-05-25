#include<iostream>
using namespace std;
// Find how manytimes the sorted-array has been rotated
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

    int count = 1;
    bool rotated = false;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i-1]) 
            count++;
        else
        {
            rotated = true;
            break;
        }
    }

    if(rotated)
        cout << "The array has been rotated " << count << " times." << endl;
    else
        cout << "The array is completely sorted";

    
    return 0;
}