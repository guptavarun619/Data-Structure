#include<iostream>
#include<limits>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    while(t)
    {
        string s;
        getline(cin, s);
        // cout << s << endl;
        int len = s.length()/2;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == s[i + len + 1])
                cout << "0";
            else 
                cout << "1";
        }
        cout << endl;
        t--;
    }
    return 0;
}