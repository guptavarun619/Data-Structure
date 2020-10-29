#include<iostream>
using namespace std;

int power(int n, int k)
{
    if(k == 0)
        return 1;
    return n * (power(n, k-1));
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k;
    cout << "n^k = " << power(n,k) << endl;
    return 0;
}