#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    string str;
    getline(cin, str);
    char ch;
    int count = 1;

    int i = 0;
    ch = str[i];
    for(i = 1; i < str.length(); i++)
    {
        if(str[i] == ch)
            count++;
        else
        {
            cout << ch << count ;
            ch = str[i];
            count = 1;
        }
    }
    cout << ch << count;

    return 0;
}