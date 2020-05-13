#include<iostream>
using namespace std;

int* fun()
{
    int *a = new int[5];
    cout << a << endl;
    for(int i = 0; i < 5; i++)
    {
        a[i] = i + 1; 
        cout << a[i] << " ";
    }
    cout << endl;

    return a;    
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int *b = fun();

    cout << b << endl;
    // cout << sizeof(b)<< endl;
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}