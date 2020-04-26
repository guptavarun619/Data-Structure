#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

// Comparator function to compare string on basis of length of strings
bool compare(string a, string b)
{
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length() > b.length();
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    cin.get();

    string s[n];
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
        // NOTE: cin.getline() doesn't work for string we need to call getline() with cin as first parameter
        cout << s[i] << endl;
    }
    sort(s,s+n, compare);
    cout << "Sorted Strings are : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
    

    return 0;
}