#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, a[100];
    cout << "Enter the size of an array : ";
    cin >> n;

    cout << "Enter the elemets of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    cout << "The maximum valued element is : " << max << endl;
    cout << "The minimum valued element is : " << min << endl;

    return 0;
}