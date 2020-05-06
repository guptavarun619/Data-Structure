#include<iostream>
#include<cctype>
using namespace std;

char check(char c)
{
    if(islower(c))
        return 'L';
    else if(isupper(c))
        return 'U';
    else 
        return 'I';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    char ch;
    cin >> ch;
    cout << check(ch);
    return 0;
}