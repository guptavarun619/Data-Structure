#include<iostream>
using namespace std;
// Replace "Pi" with "3.14" inplace
void replacePi(char *s, int i)
{
    if(s[i] == '\0')
        return;
    
    // loop for pi at current location
    if((s[i] == 'p' || s[i] == 'P') && (s[i+1] == 'i' || s[i+1] == 'I'))
    {   //shifting followed by inplace replacement wiht 3.14
        int j = i+2;
        while(s[j] != '\0')//j is moved to the last to string 
            j++;
        while(j > i+2)
        {
            s[j+2] = s[j];
            j--;
        }
        
        s[i] = '3';
        s[i+1] = '.';
        s[i+2] = '1';
        s[i+3] = '4';
        // replacePi(s, i+1); // this also works but the next line call will save you 3 recursive calls 
        replacePi(s, i+4);
    }
    else
        replacePi(s, i+1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    char s[100];
    cin >> s;
    replacePi(s, 0);

    cout << s << endl;

    return 0;
}