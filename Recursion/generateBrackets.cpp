#include<iostream>
using namespace std;
// Generate Balanced Brackets using N Pairs of Round Brackets
// example: for N=2
// ()(), (())

void generate_brackets(char out[], int n, int idx, int open, int close)
{
    // base case
    if(idx == 2*n)
    {
        out[idx] = '\0';
        cout << out << endl;
        return;
    }

    // rec case
    // 2 options
    // option 1 
    if(open<n)
    {
        out[idx] = '(';
        generate_brackets(out, n, idx+1, open+1, close);
    }
    if(close < open)
    {
        out[idx] = ')';
        generate_brackets(out, n, idx+1, open, close+1);
    }
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;

    char out[2*n];
    int idx = 0;

    generate_brackets(out, n, 0, 0, 0);

    return 0;
}