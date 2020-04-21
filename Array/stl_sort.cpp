#include<iostream>
#include<algorithm>
using namespace std;

// comparator function
bool compare(int a, int b) {
    return a > b;
}

int main()
{
    int n;
    int a[100];
     
    cout << "Enter the size of array : ";
    cin >> n;

    cout << "Enter the elements of an array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(a, a+n, compare);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    } cout << endl;
    

    return 0;
}