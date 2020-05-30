#include<iostream>
#include<climits>
using namespace std;
// Given a sorted array and key, 
// find the element which produces minimum absolute difference with key 
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
    int ans, minDiff = INT_MAX;
    while(s <= e)
    {
        mid = s + ((e - s) / 2);
        int tempDiff = key - a[mid];
        if(tempDiff < 0)
            tempDiff *= -1;
        if(tempDiff == 0)
        {
            ans = mid;
            break;
        }
        else if(tempDiff > 0)
        {
            if(tempDiff < minDiff)
            {
                ans = mid;
                minDiff = tempDiff;
            }
            s = mid + 1;
        }
        else
        {
            if(tempDiff < minDiff)
            {
                ans = mid;
                minDiff = tempDiff;
            }
            e = mid - 1;
        }   
    }
    cout << a[ans] << endl;
    return 0;
}