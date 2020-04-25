#include<iostream>
using namespace std;
// read a sentence/paragraph and store in character array

// cin.get() reads a single character at a time
// by putting a loop to read characters till you get '\n' (new line) 
void readline(char a[], int maxLen) {
    int i=0;
    char ch = cin.get();
    while (ch != '\n')
    {
        a[i] = ch;
        i++;
        ch = cin.get();
        if(i == maxLen){
            break;
        }
    }
    a[i] = '\0';
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    char a[1000];
    // This will only accept a 1st word as cin does't accept " "(space) as input
    // cin >> a;
    // cout << a << endl;
    // readline(a, 100);
    cin.getline(a, 100, '\n');
    cout << a << endl;
    return 0;
}