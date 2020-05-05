#include<iostream>
#include<vector>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    string n;
    cin >> n;

    int i = 0;
    if(n[i] != '9' && n[i] >= '5') 
    {
        n[i] = (char) ('9' - n[i]) + 48 ;
    }    
    cout << n[i];  

    for (i = 1; i < n.size(); i++)
    {
        if(n[i] >= '5') 
        {
            n[i] = (char) ('9' - n[i]) + 48 ;
        }    
        cout << n[i];
    }
    
    

    return 0;
}