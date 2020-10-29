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

    int largest = INT_MAX;
    int smallest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        largest = max(largest, a[i]);
        smallest = min(smallest, a[i]);
    }

    cout << "The maximum valued element is : " << largest << endl;
    cout << "The minimum valued element is : " << smallest << endl;

    return 0;
}