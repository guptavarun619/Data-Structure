#include<iostream>
using namespace std;

int numberOfWays(int n)
{
    if(n<=3)
        return 1;
    
    return numberOfWays(n-1) + numberOfWays(n-4);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    
    cout << numberOfWays(n) << endl;

    return 0;
}