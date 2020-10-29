#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    // char a[][10] = {{'v','a','r','u','n','\0'}, {'v','a','i','b','h','a','v','\0'}};
    // char a[][10] = {"varun", "vaibhav"};

    // cout << a[0] << endl;
    // cout << a[1] << endl;

    // Read a list of strings and we will store them in a 2D character array
    int n;
    cin >> n;
    char str[n][10];
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cin.getline(str[i], 10);
        cout << str[i] << " " << sizeof(str[i]) << endl;
    }
    
    
    return 0;
}