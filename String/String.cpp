#include<iostream>
#include<string>
using namespace std;
 
int main()
{
    //String initialization
    string s0; // Here s0 is a string object
    string s1("Hello"); // Intialized with some value

    string s2 = "Hello World!"; // Another way to initialize string with a value
    string s3(s2); // Initialize a string by coping value from other string initailized previously

    char a[] = {'a', 'b', 'c', '\0'};
    string s4(a); // String initailized using copy constructor (copying value from a charArray)

    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;

    // To check weather the string is empty or not
    if(s0.empty()) {
        cout << "s0 is an empty string" <<endl;
    }

    // To append somthing to a string
    s0.append("This string is taken");
    cout << s0 << endl;
    s0 += ", string concatination has never been easy!";
    cout << s0 << endl;

    // To clear everything from the string 
    cout << "Length of string s0 : " << s0.length() << endl;
    s0.clear();
    cout << "Length of string s0 : " << s0.length() << endl;
    
    // Compare two strings
    s0 = "Google";
    s1 = "Apple";
    cout << s0.compare(s1) << endl; // Returns an interger = 0 for equal, > 0 or < 0 lexographically

    //Overloaded Operator 
    if(s0 > s1) {
        cout << "Google is lexographically greater than Apple. " << endl;
    }

    // Characters can be accessed by index
    cout << "First character of s0 is : " << s0[0] << endl;

    // Find Substrings;
    string s = "I want apple MacBook Pro";
    int idx = s.find("apple");
    cout << idx << endl;

    // Remove word from string 
    string word = "apple";
    s.erase(idx, word.length()+1);
    cout << s << endl;

    // Iterate over all the characters in the string 
    for (int i = 0; i < s1.length(); i++)
    {
        cout <<s1[i]<<":";
    }
    cout << endl;
    // Using Iterators   
    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << ",";
    }
    cout << endl;
    // ForEach loop
    for(char c:s1)
    {
        cout << c << ".";
    }
    

    return 0;
}