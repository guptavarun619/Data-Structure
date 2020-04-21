#include<iostream>
using namespace std;

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n ; i++)
    {
        int e = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > e) {
            a[j+1] = a[j];
            j--;
        }   
        a[j+1] = e;
    }
}

int main()
{
    int n;
    int a[100];

    cout << "Enter the size of Array :";
    cin >> n;

    cout << "Enter the elements of array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    insertion_sort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}