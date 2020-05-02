#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Triplet
{
    int x, y, z;
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, key;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> key;

    sort(a, a+n); 

    vector<Triplet> trip;
    for (int i = 0; i < n-2; i++)
    {
        int j = i+1, k = n-1;
        while(j<k)
        {
            if(a[j] + a[k] == key - a[i])
            {
                trip.push_back({a[i], a[j], a[k]});
                j++;
                k--;
            }
            else if(a[j] + a[k] > key - a[i])
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    for (int i = 0; i < trip.size(); i++)
    {
        cout << trip[i].x << ", " << trip[i].y << " and " << trip[i].z << endl;
    }
    
    
    
    return 0;
}