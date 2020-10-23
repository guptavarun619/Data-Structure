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

void deleteEle(stack<int> &s, int k)
{
    if(k == 1)
    {
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    deleteEle(s, k-1);
    s.push(val);
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

    int mid = (s.size()/2) + 1;
    // cout << "Mid " << mid << endl;
    deleteEle(s, mid);

    showstack(s);

    return 0;
}