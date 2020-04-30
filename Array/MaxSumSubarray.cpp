#include<iostream>
#include<climits>
using namespace std;
// NOTE: THE GIVEN ARRAY SHOULD BE SORTED ROW AND COLUMN WISE;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int a[100][100], row, col;
    
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }

    // Preparing Suffix Sum matrix (Opposite of prefix sum ofc)
    for (int i = row - 1; i >= 0; i--)
    {
        int temp = 0;
        for (int j = col - 1; j >= 0; j--)
        {
            temp += a[i][j];
            a[i][j] = temp;
        }
    }
    

    for(int i = col - 1; i >= 0; i--) 
    {
        int temp = 0;
        for(int j = row - 1; j >= 0; j--) 
        {
            temp += a[j][i];
            a[j][i] = temp;
        }
    }

    // Traverse through matrix for maximum valued element/ max sum (whatever you call it)
    int maxSum = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            maxSum = max(maxSum, a[i][j]);
        }
    }
    
    cout << "Maximum Sum is : " << maxSum;
    
    return 0;
}