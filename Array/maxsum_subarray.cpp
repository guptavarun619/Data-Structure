#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100];
    int maxSum = 0;
    int tempSum = 0;
    int left_pos = -1, right_pos = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Generate All sub-array

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                // cout << a[k] << " ";
                tempSum += a[k];
            }
            // cout << endl;
            if (maxSum < tempSum)
            {
                maxSum = tempSum;
                left_pos = i;
                right_pos = j;
            }
            tempSum = 0;
        }
    }
    cout << "The sub-array is : ";
    for (int i = left_pos; i <= right_pos; i++)
    {
        cout << a[i] << " ";
    } cout << endl;
    cout << "Maximum sum is : " << maxSum << endl;
    return 0;
}