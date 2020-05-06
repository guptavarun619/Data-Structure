#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n;
    int a[n];
    for(int i = n - 1;i>=0;i--)
    {
        cin >> a[i];
    }
    
    cout << endl;
    
    cin >> m;
    int b[m];

    for(int i = m - 1;i>=0;i--)
    {
        cin >> b[i];
    }   
    cout <<endl;
    int length = max(m, n) + 1;
    int sum[length] = {0};
    bool carry = false;

    for(int i=0; i<length; i++)
    {
        if(carry)
        {
            sum[i] += 1;
            carry = false;
        }
            
        if(i < n)
        {
            if(sum[i] + a[i] > 9)
                carry = true;
            sum[i] = (sum[i] + a[i])%10;
            // cout << a[i] << " ";
        }

        if(i < m)
        {
            if(sum[i] + b[i] > 9)
                carry = true;
            sum[i] = (sum[i] + b[i])%10;
            // cout << b[i] << endl;
        }    
        
    }
    int i = length - 1;
    if(sum[i])
        cout << sum[i] << ", ";
    for (i = length - 2; i >= 0; i--)
    {
        cout << sum[i] << ", ";
    }
    
    cout << "END";
    
    return 0;
}