#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n], count = 1, tmp1, tmp2;
        vector<int> c;
        bool up = false;
        cin >> tmp1;
        for(int i=0; i<n-1; i++)
        {
            cin >> tmp2;
            a[i] = tmp1 - tmp2;
            tmp1 = tmp2;
        }
        for(int i=0; i<n-1; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n-1; i++)
        {
            if(a[i] > 0) // UP
            {
                if (count > 1)
                    count = count + 1 ; 
                else 
                {
                    c.push_back(count);
                    count = 1;
                }
                up = true;
            }
            else
            {
                if(up)
                {
                    up = false;
                    count = count + 1 ; 
                    c.push_back(count);
                }
                else
                {
                    if (count > 1)
                        count = count + 1 ; 
                    else 
                    {
                        c.push_back(count);
                        count = 1;
                    }
                }
                
            }
        }
        for (int i = 0; i < c.size(); i++)
        {
            cout << c[i] << " ";
        }
        cout << endl;
    };
    return 0;
}