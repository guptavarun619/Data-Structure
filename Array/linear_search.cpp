#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[100];
    int key;
    bool found = false;

    cout << "Enter the size of Array :";
    cin >> n;

    cout << "Enter the elements of array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the element you want to search :";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            cout << key << " found at " << i << " index" << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << key << " not found" << endl;

    return 0;
}