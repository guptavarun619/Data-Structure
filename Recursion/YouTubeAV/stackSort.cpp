#include<bits/stdc++.h>
using namespace std;

void showstack(stack<int> s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

void insert(stack<int> &a, int tmp)
{   // base
    if(a.size() == 0 || a.top() <= tmp)
    {
        a.push(tmp);
        return;
    }
    int val = a.top();
    a.pop();
    insert(a, tmp);
    a.push(val);
    return;        
}

void srt(stack<int> &a)
{
    if(a.size() == 1) // base
        return;
    int val = a.top();
    a.pop();
    srt(a);
    insert(a, val);
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(4);

    srt(s);

    cout << "Sorted stack is : ";
    showstack(s);

    return 0;
}