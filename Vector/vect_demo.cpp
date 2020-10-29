#include<iostream>
#include "vect.h"
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.pop_back();
    v.push_back(5);
    v.push_back(6);

    cout << "Capacity : " << v.capacity() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;    

    return 0;
}