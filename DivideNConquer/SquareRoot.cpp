#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int a; 
    cin >> a;
    cout << a << endl;

    int s = 0, e = a;
    int mid;

    bool found = false;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if ((mid*mid) == a)
        {
            found = true;
            break;
        }
        else if ((mid*mid) < a)
            s = mid + 1;
        else
            e = mid - 1;
    };
    if(found)
        cout << mid << " is the square root of " << a << endl;
    else
        cout << "Not a perfect square" << endl;
    
    return 0;
}