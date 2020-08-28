#include<iostream>
using namespace std;

// time complexity = O(n);
int power(int a, int b)
{
    if(b == 1)
        return a;
    return a*power(a,b-1);
}

// time complexity = O(log(base2)(n));
int fast_power(int a, int b)
{
    if(b == 1)
        return a;

    int temp = fast_power(a, b/2);      
    temp *= temp;  
    if(b%2 == 0) //exponent is even
        return temp;
    else
        return a * temp; 
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int a, b;
    cin >> a >> b;
    // cout << a << "^" << b << " = " << power(a, b) << endl;
    cout << a << "^" << b << " = " << fast_power(a, b) << endl;

    return 0;
}