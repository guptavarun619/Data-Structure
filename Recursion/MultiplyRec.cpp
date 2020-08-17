// Multiply two numbers whithout using * operator using recursion
#include<iostream>
using namespace std;

int mult(int a, int b)
{
    if(b == 0)
        return 0;
    return a + mult(a, b-1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int a, b;
    cin >> a >> b ;
    cout << a << " * " << b << " = " << mult(a, b) << endl;
    return 0;
}