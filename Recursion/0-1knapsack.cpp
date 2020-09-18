#include<iostream>
#include<climits>
using namespace std;

int profit(int N, int C, int *wt, int *prices) 
{
    // base case
    if(N==0 || C == 0)
        return 0;
    
    // rec case
    int ans = 0, inc, exc;
    inc = exc = INT_MIN;
    // include the item
    if(C >= wt[N-1])
        inc = prices[N-1] + profit(N-1, C-wt[N-1], wt, prices);
    // exclude the item
    exc = profit(N-1, C, wt, prices);

    ans = max(inc, exc);
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, c;
    cin >> n >> c;
    int weights[n], prices[n];
    for(int i = 0; i < n; i++)
        cin >> weights[i];
    for(int i = 0; i < n; i++)
        cin >> prices[i];

    cout << profit(n, c, weights, prices);

    return 0;
}