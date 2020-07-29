#include<iostream>
#include<vector>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    vector<int> d{1,2,3,5,4};
    d.push_back(12);
    // Push back O(1) for most of the time 
    // would be more incase of expanding the array

    // Remove last element O(1)
    d.pop_back();

    // Insert some elements in the middle
    // d.insert(d.begin() + 3, 100);
    // vector.insert(poiter to the location, element/value);
    d.insert(d.begin() + 3, 4, 100);
    // vector.insert(poiter to the location, no of elemets, element/value);
    // Complexity O(n) where n = no of elements added + no of elements shifted


    // erase some element in the middle
    // d.erase(d.begin() + 3);
    // vector.erase(pointer to the element)
    d.erase(d.begin()+3, d.begin()+7);
    // vector.erase(pointer to the range)

    // size
    cout << "Size : " << d.size() << endl;
    cout << "Capacity : " << d.capacity() << endl;
    // vector doesn't shrink for performance

    d.resize(18);
    cout << "After resize " << endl;
    cout << "Size : " << d.size() << endl;
    cout << "Capacity : " << d.capacity() << endl;
    // here we can see that resize impact only the size 
    // if resize value is less than the capacity
    // but capacity increases with increase in size(beyond current capacity)

    // remove all the elements of the vector, 
    // doesn't delete the memory occupied by the array
    d.clear();
    cout << "After clear " << endl;
    cout << "Size : " << d.size() << endl;
    cout << "Capacity : " << d.capacity() << endl;

    if(d.empty())
        cout << "The Vector is now empty " ;

    for(int x : d)
        cout << x << " ";
    cout << endl;

    d.push_back(10);
    d.push_back(15);
    d.push_back(20);
    cout << "Front element : " << d.front() << endl;
    cout << "Last element : " << d.back() << endl;

    // Reserve
    int n;
    cin >> n;
    vector<int> v;
    // To avoid doubling, we will use reserve funtion 
    v.reserve(1000);
    // comment line71 and uncomment line79 to see how doubling the size and allocation takes place

    for(int i=0; i < n; i++)
    {
        int no;
        cin >> no;
        v.push_back(no);
        // cout << "Changing capacity : " << v.capacity() << endl;
    }
    cout << "Capacity : " << v.capacity() << endl;

    for(int x:v)
        cout << x << " ";
    cout << endl;

    return 0;
}