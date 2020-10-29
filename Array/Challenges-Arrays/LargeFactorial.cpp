#include<iostream>
#include<vector>
#define MAX 1500

using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    
    int a[MAX] = {0};
    a[0] = 1;
    int s = 1;

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < s; j++)
        {
            int tmp = a[j] * i;
            tmp += carry;
            carry = tmp/10;
            a[j] = tmp%10;
        }
        while(carry)
        {
            a[s] = carry%10;
            carry /= 10;
            s++;
        }
    }

    for (int i = s-1; i >= 0; i--)
        cout << a[i]; 

    return 0;
}