#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    char a[n], ch;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int i = 0, j = n - 1;
    bool palindrome = true;
    while(i < j)
    {
        if(a[i] != a[j])
        {
            palindrome = false;
            break;
        }
        i++;
        j--;
    }
    if(palindrome)
        cout << "true" ;
    else 
        cout << "false";

    return 0;
}