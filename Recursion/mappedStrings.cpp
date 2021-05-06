#include <bits/stdc++.h>
using namespace std;

char str[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void solve(string inp, int inpCur, int *out, int outCur) {
    // base case
    if (inp[inpCur] == '\0') {
        // print the corresponding charaters
        // for(int num : out) {
        //     cout << str[num] << endl;
        // }
        for(int i = 0; i < outCur; i++) {
            cout << str[out[i]-1] ;
        }
        cout << "\n";
        return;
    }
    // rec case
    // take single digit
    out[outCur] = inp[inpCur] - 48;
    solve(inp, inpCur+1, out, outCur+1);
    // check for double digit
    if(inp[inpCur+1] <= '6' && inp[inpCur+1] >= '0') {
        // cout << "T : " << (inp[inpCur]-48)*10 << " 0 : " << inp[inpCur+1]-48 << endl;
        int temp = ((inp[inpCur]-48)*10) + inp[inpCur+1]-48;
        // cout << "temp " << temp << endl;
        out[outCur] = temp;
        solve(inp, inpCur+2, out, outCur+1);
    }
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif    
    string inp;
    cin >> inp;
    int len = inp.length();
    int out[len];
    solve(inp, 0, out, 0);

    return 0;
}