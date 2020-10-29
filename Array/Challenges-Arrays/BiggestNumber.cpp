#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b)
{
    string str1 = to_string(a);
    string str2 = to_string(b);

    string s1 = str1.append(str2);
    string s2 = str2.append(str1);

    return s1 > s2;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++)
            cin >> a[i];
        
        sort(a, a+n, compare);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    };
    return 0;
}