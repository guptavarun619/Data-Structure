#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    string str;
    getline(cin, str);

    unordered_map<char, int> charFreq;
    for(int i = 0; i < str.length(); i++)
    {
        charFreq[str[i]]++;
    }
    
    int maxCount = INT_MIN;
    char ch;
    for (auto i = charFreq.begin(); i != charFreq.end(); i++)
    {
        if(i->second > maxCount)
        {
            ch = i->first;
            maxCount = i->second;
        }
    }

    cout << ch;
    
    return 0;
}