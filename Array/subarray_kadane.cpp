#include<iostream>
using namespace std;

int main()
{
    int a[100];
    int n, tempSum = 0, maxSum = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Kadana's algorithm
    for (int i = 0; i < n; i++)
    {
        if(tempSum+a[i] > 0)
            tempSum += a[i];
        maxSum = max(maxSum, tempSum);
    }
    
    cout << "Maximum sum for a subarray is : " << maxSum << endl;
    
    return 0;
}