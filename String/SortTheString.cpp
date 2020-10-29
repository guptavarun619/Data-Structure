#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int convertToInt(string str)
{
    int temp = 0;
    int power = 1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        temp += (str[i]-'0')*power;
        power *= 10;
    }
    return temp;
}

bool numericCompare(pair<string, string> a, pair<string, string> b)
{
    return convertToInt(a.second) < convertToInt(b.second);
}

bool lexiographicCompare(pair<string, string> a, pair<string, string> b)
{
    return a.second < b.second;
}

string extractStringAtKey(string str, int key)
{
    char *s = strtok((char *)str.c_str(), " ");
    while (key>1) {
        s = strtok(NULL," ");
        key--;
    }
    return (string)s;   
}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    cin.get();

    string a[100];

    for (int i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }

    int key;
    string reversal, order;
    cin >> key >> reversal >> order;

    pair<string,string> strPair[100];

    for (int i = 0; i < n; i++)
    {
        strPair[i].first = a[i];
        strPair[i].second =  extractStringAtKey(a[i], key);
    }
    
    // Sort
    if(order == "numeric") 
    {
        sort(strPair, strPair + n, numericCompare);
    }
    else
    {
        sort(strPair, strPair + n, lexiographicCompare);
    }
    
    // Reversal
    if(reversal == "true") {
        for (int i = 0; i < n/2; i++)
        {
            swap(strPair[i], strPair[n-i-1]);
        }
        
    }

    // Output
    for (int i = 0; i < n; i++)
    {
        cout << strPair[i].first << endl;
    }
    
    return 0;
}