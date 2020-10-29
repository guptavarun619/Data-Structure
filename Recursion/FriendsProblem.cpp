#include<bits/stdc++.h>
using namespace std;

int number_of_ways(int n)
{
    if(n <= 1)
        return 1;

    return number_of_ways(n-1) + ((n-1) * number_of_ways(n-2));
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    cout << number_of_ways(n) << endl;
    return 0;
}