#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    // Declaration of pair
    pair<int, char> p;
    // Initailizing value of pair
    p.first = 10;
    p.second = 'B';

    // Another way to declare a pair
    // using the copy constructor
    pair<int, char> p2(p);

    cout << p2.first << " ";
    cout << p2.second << endl;

    // Declaring and initailizing it's value 
    pair<int, string> p3 = make_pair(100, "Audi");
    cout << p3.first << " ";
    cout << p3.second << endl;

    // Taking input from the user
    int a, b;
    cin >> a >> b;
    pair<int, int> p4 = make_pair(a, b);
    cout << p4.first << " ";
    cout << p4.second << endl;
    return 0;
}