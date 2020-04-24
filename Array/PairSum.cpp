#include<iostream>
using namespace std;

// Given a Sorted Array, Find Pair of Elements that sum to K(Given)
int main()
{
    int a[] = {1, 3, 5, 7, 10, 11, 12, 13};
    int key;
    
    key = 16;

    int i = 0;
    int j = sizeof(a)/sizeof(int)-1;

    while (i < j) {
        int currentSum = a[i] + a[j];
        if(currentSum > key)
            j--;
        else if (currentSum < key)
            i++;
        else
        {
            cout << a[i] << " + " << a[j] << " = " << key << endl;
            i++;
            j--;
        }
    }
    return 0;
}