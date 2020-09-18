// Generate all possible strings using the given sequence of input and maped characters
// 1->A, 2->B, 3->C ......
// example : input : 1234
// 1 2 3 4 => A B C D
// 12 3 4 => L C D
// 1 2 34 but 34 is not a valid index for character(NOT POSSIBLE)
// 1 23 4 => A W D
#include<iostream>
using namespace std;

void generate_strings(char *in, char *out, int i, int j)
{
    // base case
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    // rec case - two options
    // one digit at a time
    int digit = in[i] - '0';
    if(digit != 0)
    {
        char ch = digit + 'A' - 1;
        out[j] = ch;
    }
    generate_strings(in, out, i+1, j+1);

    // two digit at a time
    if(in[i+1] != '\0')
    {
        int secondDigit = in[i+1] - '0';
        int number = (digit*10) + secondDigit;
        if(number <= 26)
        {
            ch = number + 'A' - 1;
            out[j] = ch;
            generate_strings(in, out, i+2, j+1);
        }
    }
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    char ch[100];
    cin >> ch;

    char out[100];
    generate_strings(ch, out, 0, 0);
    
    return 0;
}