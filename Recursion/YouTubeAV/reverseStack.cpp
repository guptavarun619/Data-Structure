#include<bits/stdc++.h>
using namespace std;
// here midle reffers to [(n/2) + 1]th element

void showstack(stack<int> s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

void insertEle(stack<int> &s, int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }
    int val = s.top();
    s.pop();
    insertEle(s, ele);
    s.push(val);
    return;
}

void reverseStack(stack<int> &s)
{
    if(s.size() == 1)
        return;
    int val = s.top();
    s.pop();
    reverseStack(s);
    insertEle(s,val);
    return;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    showstack(s);

    reverseStack(s);

    showstack(s);

    return 0;
}