// 0, 1, 1, 2, 3, 5, 8 ....
// 0, 1, 2, 3, 4, 5, 6th
// Place /\

#include<iostream>
using namespace std;

int fibo(int n)
{
    if(n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibo(n-1) + fibo(n-2);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;

    cout << fibo(n);
    return 0;
}