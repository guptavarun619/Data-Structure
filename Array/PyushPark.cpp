#include<iostream>
using namespace std;

// Pyush needs to escape the park with min k strength
// * will increase strength by 5
// . will decrease strength by 2
// # will block him and he needs to skip that row
// NOTE: Pyush can only traverse through the park(matrix) row-wise

int main()
{
    int m, n, s, k;
    bool succcess = true;
    char a[100][100];
    cin >> m >> n >> s >> k;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(s < k)
            {
                succcess = false;
                break;
            }
            if(a[i][j] == '.') {
                s -= 2;
            }
            else if (a[i][j] == '*') {
                s += 5;
            }
            else
            {
                break;
            }
            if(j != n-1)
                s--;
        }
    }
    
    if(succcess) {
        cout << "Yes" << endl;
        cout << s << endl;
    }
    else 
    {
        cout << "No" << endl;
    }
    
    return 0;
}