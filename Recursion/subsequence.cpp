// Subsequence/Subset can be non-contigous where as subarray is contigous
// Given a string containing n charactes find out the subsets of that string.
#include<iostream>
using namespace std;

void subsequence(char *in, char *out, int i, int j)
{
    // base case
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << " ";
        return; 
    }

    // rec case
    // include the current char
    out[j] = in[i];
    subsequence(in, out, i+1, j+1);

    // exclude the current char
    subsequence(in, out, i+1, j);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    char a[10], out[10];
    cin >> a;

    subsequence(a, out, 0, 0);
    
    return 0;
}