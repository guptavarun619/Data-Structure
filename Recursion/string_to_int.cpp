#include<iostream>
using namespace std;

int string_to_integer(string str, int len)
{
    if(len <= 0)
        return 0;

    int a = str[len-1] - '0';
    int temp = string_to_integer(str, len-1);

    return (temp*10) + a;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    string n;
    cin >> n;

    int a = string_to_integer(n, n.length());
    cout << a << endl;
    return 0;
}