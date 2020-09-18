#include<iostream>
using namespace std;

void towerOfHanoi(int n, char src, char helper, char dest)
{
    // base case
    if(n==0)
        return;
    
    //  rec case
    // move n-1 disk from src to helper
    towerOfHanoi(n-1, src, dest, helper);
    cout << "Shift disc " << n << " from " << src << " to " << dest << endl;
    towerOfHanoi(n-1, helper, src, dest);

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;

    towerOfHanoi(n, 'a', 'b', 'c');

    return 0;
} 