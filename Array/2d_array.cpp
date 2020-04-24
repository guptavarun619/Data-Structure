#include<iostream>
using namespace std;

int main()
{
    int a[4][3] = {0};
    int count = 1;
    // Iterate over array to take input
    for (int row = 0; row < 4; row++) 
    {
        for (int col = 0; col < 3; col++)
        {
            a[row][col] = count++;
            cout << a[row][col] << " ";
        }
        cout << endl;
    }
    
    return 0;
}