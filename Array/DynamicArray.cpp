#include <iostream>

using namespace std;

int main()
{
    int A[5] = {1, 3, 5, 7, 9}; // Static array declaration

    int *p;         // Declaring pointer for Dynamic Array
    p = new int[5]; // Dynamic Array declaration using pointer
    p[0] = 2;
    p[1] = 4;
    p[2] = 6;
    p[3] = 8;
    p[4] = 10;

    // Traversal through Dynamic vs Static Array
    cout << "Elements of Static Arrays are: ";
    for (int i = 0; i < 5; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "Elements of Dynamic Arrays are: ";
    for (int i = 0; i < 5; i++)
        cout << p[i] << " ";
    cout << endl;

    // Increasing the size of dynamic Array
    int *q;         // Declaration of pointer for new Array
    q = new int[7]; // New Array declared in Heap
    //Coping elements for orignal array to new array.
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    delete[] p; // Deleted orignal array
    p = q;      // pointer of orignal array points to new array
    q = NULL;   //redundant pointer for an array
    p[5] = 12;
    p[6] = 14;
    cout << "Elements of new Dynamic Arrays are: ";
    for (int i = 0; i < 7; i++)
        cout << p[i] << " ";
    cout << endl;
    delete[] p; // Delete the array in heap after use
    return 0;
}