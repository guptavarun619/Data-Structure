#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    // Array constructor to create a new array
    Array()
    {
        cout << "Enter the size of an array ";
        cin >> size;
        A = new int[size];
        length = 0;
    }
    // To display each element of an array
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
    // To add new element to array from end
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
    // To add new element to array at particular index
    void insert(int index, int x)
    {
        if (index < length + 1 && index > -1)
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
                cout << "No more Element can be inserted to this Array for now" << endl;
            }
        }
    }
    // To replace the value of an element for specific index
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
    // To delete an element for specific index
    void remove(int index)
    {
        if (index < length && index > -1)
        {
            for (int i = index; i < length - 1; i++)
            {
                A[i] = A[i + 1];
            }
            cout << "Element at " << index << " has been deleted" << endl;
            length--;
        }
        else
        {
            cout << "Index out of range" << endl;
        }
    }
    // Search a particular element
    // NOTE: Linear Search is performed we don't know if the array is sorted or not
    void search(int key)
    {
        bool found = false;
        for (int i = 0; i < length; i++)
        {
            if (A[i] == key)
            {
                found = true;
                cout << key << " found at " << i + 1 << " position" << endl;
                break;
            }
        }
        if (!found)
            cout << key << " not found in array" << endl;
        ;
    }
};

int main()
{
    Array arr;
    arr.append(5);
    arr.append(6);
    arr.append(9);
    arr.display();

    arr.search(8);

    // arr.insert(3, 8);
    // arr.display();

    // arr.replace(0, 1);
    // arr.display();

    // arr.replace(3, 4);
    // arr.display();

    // arr.remove(1);
    // arr.display();

    return 0;
}