#include<iostream>
using namespace std;

float squareRoot(int a)
{
    int s = 0, e = a;
    int mid;

    float ans;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if ((mid*mid) == a)
        {
            ans = mid;
            break;
        }
        else if ((mid*mid) < a)
        {
            ans = mid;
            s = mid + 1;
        }   
        else
            e = mid - 1;
    };

    float inc = 0.1;
    
    for(int prec = 0; prec < 5; prec++)//loop for precision
    {
        while(ans*ans <= a)
            ans += inc;
        
        ans -= inc;
        inc /= 10;
    }

    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int a; 
    cin >> a;
    // cout << a << endl;

    cout << squareRoot(a);
    
    return 0;
}