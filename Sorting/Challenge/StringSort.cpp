#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string a, string b)
{
    bool subEq = true;
    int len = a.length() < b.length() ? a.length() : b.length();
    for (int i = 0; i < len; i++)
    {
        if(a[i] != b[i])
        {
            subEq = false;
            break;
        }
    }
    if(subEq)
    {
        if(a.length() > b.length())
            return true;      
    }
    else
    {
        if(a < b)
            return true;
    }

    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    cin.ignore();
    vector<string> a;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.emplace_back(tmp);
        // cout << a[i] << endl;
    }

    sort(a.begin(), a.end(), compare);

    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    

    return 0;
}