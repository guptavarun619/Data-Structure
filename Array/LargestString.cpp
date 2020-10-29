#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    cin.get();

    char currentString[100];
    char largestString[100];
    int len = 0, largestLen = 0;
    for (int i = 0; i < n; i++)
    {
        cin.getline(currentString, 100, '\n');
        cout << currentString << endl;
        len = strlen(currentString);
        if(strlen(largestString) < len)
        {
            largestLen = len;
            strcpy(largestString, currentString);
        }
    }
    cout << "The largest string is : " << largestString << ", of lenght : " << largestLen;
    return 0;
}
