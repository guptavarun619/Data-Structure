// 2-Dimentional array are simply arrays of array. Dimentions refers to
// rows and columns. Though there are 2 dimentions but the memory allocation
// is in contigous manner. It is definately index based as it's an array

#include <iostream>

using namespace std;

int main()
{
    // int A[2][2]; // Declaration of a 2-D Array without initialization
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Initialization of 2-D array

    // Declaration of 2-D array using pointer
    // int *A[3]; //this is an array of (int *) integer pointer
    // A[0] = new int[3];
    // A[1] = new int[3];
    // A[2] = new int[3];

    // Declaration of 2-D array using double pointer
    // int **A;
    // A = new int *[3];
    // A[0] = new int[3];
    // A[1] = new int[3];
    // A[2] = new int[3];
    // // Initailizing the value of 2-D arraytypename
    // int count = 0;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         A[i][j] = ++count;
    //     }
    // }

    // Printing a 2-D array.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}