// Array is a collection of elements having similar datatype
// stored at contigous memory location
#include <iostream>
#include <array>

using namespace std;

int main()
{
    // int a[5]; // Declaration of an array without pre-assignment
    int array[5] = {2, 5, 4, 7, 8}; // Declaration of an array with pre-assigning the values

    // Accessing elements of an array using index
    cout << "First Element of Array: " << array[0] << endl;
    cout << "Second Element of Array: " << array[1] << endl;

    // Accessing elements of an array using pointer
    cout << "Third Element of Array: " << *(array + 2) << endl;
    cout << "Fourth Element of Array: " << *(array + 3) << endl;

    // Size of array
    int size = sizeof(array) / sizeof(array[0]);
    cout << "Size of the array is: " << size << endl;

    // Traversal through an array
    cout << "All element of the Array are: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    // To prove the array is stored in a contigous manner, here are the address of each element
    cout << "Address of all element in Array are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << &array[i] << endl;
    }

    return 0;
}