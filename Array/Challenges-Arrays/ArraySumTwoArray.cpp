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
        cout << a[i] << " ";
    }
    cout << endl;
    cin >> m;
    int b[m];
    for(int i = m - 1;i>=0;i--)
    {
        cin >> b[i];
        cout << b[i] << " ";
    }   
    cout <<endl;
    int length = n > m ? n+1 : m+1;
    int sum[length] = {0};
    bool carry = false;
    for(int i=0; i<length; i++)
    {
        if(carry)
            sum[i] += 1;
            
        if(length - 1 >=n)
        {
            if(sum[i] + a[i] > 9)
                carry = true;
            sum[i] = (sum[i] + a[i])%10;
        }
        if(length - 1 >=m)
        {
            if(sum[i] + b[i] > 9)
                carry = true;
            sum[i] = (sum[i] + b[i])%10;
        }    
        
    }
    for(int i = length; i>=0; i--)
    {
        cout << sum[i] << ", ";
    }   
    cout << "END";
    
    return 0;
}