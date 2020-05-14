#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

bool compare(int a, int b) 
{
    return a <= b;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    // find minimum no of coins/notes required for transaction
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(coins) / sizeof(int);
    int money = 168;

    while(money > 0)
    {
        int lb = lower_bound(coins, coins+n, money, compare) - coins - 1;
        int m = coins[lb];
        cout << m << ",";
        money -= m;
    };

    return 0;
}