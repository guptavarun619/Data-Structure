#include <bits/stdc++.h>
using namespace std;
// The approach of bucket sort is similar to counting sort, in this you actually 
// place the element(object - in this case) into the bucket/index rather than just
// counting the frequency of it

// Problem Statement - Create a leader board for student marks

class Student {
    public:
    int marks;
    string name;
};

void bucket_sort(Student s[], int n) {
    // assuming marks are in the range of 0 -100
    vector<Student> v[101];
    for (int i = 0; i < n; i++) {
        int m = s[i].marks;
        v[m].push_back(s[i]);
    }

    // Reverse the vectore for desciding order and print the students
    for (int i = 100; i >= 0; i--) {
        for (vector<Student>::iterator it = v[i].begin(); it != v[i].end(); it++) {
            cout << (*it).name << " " << (*it).marks << endl; 
        }
    }
}


int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif    

    Student s[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i].marks >> s[i].name;
    }

    bucket_sort(s, n);
    
    return 0;
}