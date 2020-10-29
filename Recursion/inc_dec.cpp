#include<iostream>
using namespace std;

void dec(int n)
{
    cout << n << " ";
    if(n > 1)
        dec(n-1);
}

void inc(int n)
{
    if(n > 1)
        inc(n-1);
    cout << n << " ";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    cout << "Decreasing series : ";
    dec(n);
    cout << endl;
    cout << "Increasing series : ";
    inc(n);
    return 0;
}