#include<iostream>
using namespace std;
// 2048 -> two zero four eight 

string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void number_to_digit(int n)
{
    int tmp = n%10;
    if(n/10 > 0)
        number_to_digit(n/10);
    cout << arr[tmp] << " ";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    cout << n << " -> ";
    if(n<0)
    {
        cout << "(-)";
        n *= -1;
    }
    number_to_digit(n);

    return 0;
}