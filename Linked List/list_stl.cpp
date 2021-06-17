#include<iostream>
#include<list>
using namespace std;

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    // Declaring list
    list<int> l;
    // Initializing list with value
    list<int> numbers{1,2,3,4,5};
    // List of different datatype
    list<string> fruits{"apple", "orange", "mango", "banana"};
    fruits.push_back("pineapple"); // inserts node element to the tail 

    // sorting the list
    fruits.sort();

    // reverse the list
    fruits.reverse();

    // removing the head element (from the start of the list)
    cout << fruits.front() << endl;
    fruits.pop_front();

    // adding element to the front
    fruits.push_front("kivi");

    // removing the tail element (from the end of the list)
    cout << fruits.back() << endl;
    fruits.pop_back();

    // Iterate over the list 

    for(auto fruit = fruits.begin(); fruit != fruits.end(); fruit++) {
        cout << *fruit << " ";
    }
    cout << endl;

    fruits.push_front("banana");
    for(string fruit : fruits) {
        cout << fruit << " ";
    }
    cout << endl;

    // removing(all occurences of) an element by value from the list
    string s;
    cin >> s;
    cout << s << " will be removed if exists in the list" <<  endl;
    fruits.remove(s);

    for(string fruit : fruits) {
        cout << fruit << " ";
    }
    cout << endl;

    // erase one elements using iterator position
    auto it = fruits.begin();
    it++;
    fruits.erase(it);

    for(string fruit : fruits) {
        cout << fruit << " ";
    }
    cout << endl;

    // inserting element in the list at iterator position
    it = fruits.begin();
    it++;
    fruits.insert(it,"grape");
    for(string fruit : fruits) {
        cout << fruit << " ";
    }
    cout << endl;


    return 0;
}