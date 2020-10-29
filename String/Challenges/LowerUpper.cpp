#include<iostream>
#include<cctype>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    char ch;
    cin >> ch;

    if (isupper(ch))
        cout << "UPPERCASE";
    else if (islower(ch))
        cout << "lowercase";
    else 
        cout << "Invalid";
           
    return 0;
}