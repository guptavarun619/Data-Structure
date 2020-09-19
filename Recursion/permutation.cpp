#include<iostream>
using namespace std;

void permute(char *in, int i)
{
    // base case
    if(in[i] == '\0')
    {
        cout << in << endl;
        return;
    }

    // rec case
    for(int j = i; in[j]!='\0'; j++)
    {
        swap(in[i],in[j]);
        permute(in, i+1);
        swap(in[i],in[j]); // Backtracking - To store the previous array
    } 
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    char a[10];
    cin >> a;
    cout << a << endl;
    permute(a, 0);

    return 0;
}