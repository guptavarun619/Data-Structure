#include<iostream>
#include<cstring>
using namespace std;

bool isPalindrome(char a[])
{
    int i = 0, j = strlen(a) - 1;
    while(i <= j)
    {
        if(a[i] == a[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    char a[100];
    cin.getline(a, 100, '\n');
    if(isPalindrome(a))
        cout << "String is Palindrome!" << endl;
    else
        cout << "String is not Plaindrome!" << endl;

    return 0;
}