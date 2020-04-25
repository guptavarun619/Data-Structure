#include<iostream>
#include<cstring>
using namespace std;
// Remove consecutive duplicate characters from a string 

void removeDuplicates(char a[]) 
{
    int l = strlen(a);
    if(l < 2)
        return;
    int prev = 0;
    for (int current = 1; current < l; current++)
    {
        if(a[prev] != a[current])
        {
            prev++;
            a[prev] = a[current];
        }
    }
    a[prev+1] = '\0';
    cout << a;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    char a[1000];
    cin.getline(a, 1000);
    removeDuplicates(a);
    return 0;
}