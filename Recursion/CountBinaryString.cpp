// Count Binary Strings of Length of N, which have NO consecutive ones?
// Input is N
#include<iostream>
using namespace std;

int no_consecutive_ones(int n)
{
    if(n == 1)
        return 2;
    if(n == 0)
        return 1;
    
    return no_consecutive_ones(n-1) + no_consecutive_ones(n-2);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;

    cout << no_consecutive_ones(n) << endl;

    return 0;
}