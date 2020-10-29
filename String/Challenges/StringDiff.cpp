#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    string str;
    getline(cin, str);

    int i = 0;
    cout << str[i];
    for (i = 1; i < str.length(); i++)
    {
        cout << str[i] - str[i - 1];
        cout << str[i];
    }
    
    return 0;
}