#include<iostream>
using namespace std;

int ladder(int n, int k)
{
    if(n==0)
        return 1;
    if(n < 0)
        return 0;

    int tmp = 0;

    for(int i = 1; i <= k; i++)
    {
            tmp += ladder(n-i, k);
    }

    return tmp;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k;

    cout << ladder(n, k) << endl;

    return 0;
}