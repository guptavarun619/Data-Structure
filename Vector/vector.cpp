#include<iostream>
#include<vector>
// header file for using vector container
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    // Vector is a container similar to dynamic array, it can grow and shrink in size depending upon the system
    // It doubles itself inorder to accomodate more elements than it's size;

    // Declaration of a vector
    vector<int> a;
    // vector<data_type> variable_name;

    vector<int> b(5,10);
    // All elements initialized with same single value
    // vector<data_type> variable_name(no of elements, single value of each element);
    // This is useful to initialize a vector with some default value

    vector<int> c(b.begin(), b.end());
    // Copied vector
    // vector<data_type> variable_name(parent_vect.begin(), parent_vect.end());
    // To copy another vector

    vector<int> d{1, 2, 3, 4, 5};
    // All elements intialized with different values
    // vector<data_type> variable_name{ele1, ele2, ele3};

    // Iterating over a vector
    // Normal approach just like an array, going to each index
    for(int i = 0; i<c.size(); i++)
        cout << c[i] << " ";
    cout << endl;

    // Using iterator - NOTE: the iteratr
    for(auto it = b.begin(); it != b.end(); it++)
        cout << *it << " ";
    cout << endl;

    // Using for each loop
    // for(data_type variable:vector_name)
    for(int x:d)
        cout << x << " ";
    cout << endl;


    // User defined vector
    vector<int> v;
    int n;
    cin >> n;
    cout << "Size user asked for : " << n << endl;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        v.push_back(no);
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;    

    // Memory Level
    cout << v.size() << endl;
    cout << v.capacity() << endl; // size of underlying array
    // capacity will be in 2^n form as doubling of the memory occurs in case of push_back();
    cout << v.max_size() << endl; // maximum no of elements a vector can hold in the worst case according to available memory in the system

    cout << d.size() << endl;
    cout << d.capacity() << endl; // size of underlying array
    // capacity will be same as size because it was defined at the time of initilizing
    cout << d.max_size() << endl; // maximum no of elements a vector can hold in the worst case according to available memory in the system

    
    return 0;
}