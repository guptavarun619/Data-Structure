#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100], cs[100];
    int maxSum = 0;
    int temp = 0;
    int tempSum = 0;
    int left = -1, right = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        temp += a[i];
        cs[i] = temp;
    }

    // Using cumilative sum(pre-computing) to get max sum sub array

    cout << "The input array is ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] <<  " ";
    }   cout << endl;
    cout << "The cumilative sum array ";
    for (int i = 0; i < n; i++)
    {
        cout << cs[i] << " ";
    }   cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            tempSum = 0;
            tempSum = cs[j] - cs[i-1];
            if(tempSum > maxSum) {
                maxSum = tempSum;
                left = i;
                right = j;
            }
        }
        
    }
    cout << "The subarray is : ";
    for (int i = left; i <= right; i++)
    {
        cout << a[i] << " ";
    } cout << endl;

    cout << "Maximum sum is : " << maxSum << endl;
    return 0;
}