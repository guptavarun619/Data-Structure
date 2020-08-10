#include<iostream>
using namespace std;

int fact(int n)
{
    // base case
    if(n == 1)
        return 1;
    // recursive case
    else
        return n * fact(n-1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;

    cout << fact(n) << endl;
    return 0;
}