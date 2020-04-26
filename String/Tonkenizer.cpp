#include<iostream>
#include<cstring>
using namespace std;

// char *strtok(char *s, char *delimiters)
// return a token on each subsquent call

// on the first function call, string should be passed as a parameter for 's'
// on subsequent calls we should pass the string argument as null

int main()
{
    char s[100] = "Today is a rainy day";
    char *ptr = strtok(s, " ");
    cout << ptr << endl;

    while(ptr != NULL)
    {
        ptr = strtok(NULL," ");
        cout << ptr << endl;
    }
    

    return 0;
}