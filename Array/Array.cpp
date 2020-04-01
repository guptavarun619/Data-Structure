#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        cout << "Enter the size of an array ";
        cin >> size;
        A = new int[size];
        length = 0;
    }
    void display()
    {
        if (length)
        {
            cout << "Elements of Array are: ";
            for (int i = 0; i < length; i++)
            {
                cout << A[i] << " ";
            }
            cout << endl;
        }
        if (length < size)
            cout
                << "You are only able to see (" << length << ") element(s) as other element(s) of array are uninitialized" << endl;
    }
    void append(int x)
    {
        if (length < size)
        {
            A[length] = x;
            length++;
            cout << x << " has been added to the Array" << endl;
        }
        else
        {
            cout << "No more Element can be added to this Array" << endl;
        }
    }
    void insert(int index, int x)
    {
        if (index < size && index > -1)
        {
            if (length < size)
            {
                for (int i = length; i > index; i--)
                {
                    A[length] = A[length - 1];
                }
                length++;
                A[index] = x;
                cout << x << " has been inserted at " << index << " position" << endl;
            }
            else
            {
                cout << "No more Element can be inserted to this Array" << endl;
            }
        }
    }
    void replace(int index, int x)
    {
        if (index < size && index > -1)
        {
            A[index] = x;
            cout << x << " has been replaced at " << index << " position" << endl;
            if (length <= index)
                length = index + 1;
        }
        else
        {
            cout << "Index out of range" << endl;
        }
    }
};

int main()
{
    Array arr;
    arr.append(5);
    arr.append(6);
    arr.append(9);
    arr.display();

    arr.insert(4, 8);
    arr.display();

    // arr.replace(0, 1);
    // arr.display();

    // arr.replace(3, 4);
    // arr.display();

    return 0;
}