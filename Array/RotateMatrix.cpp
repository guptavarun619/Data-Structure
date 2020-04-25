#include<iostream>
#include<algorithm>
using namespace std;

void rotate_transpose(int a[][100], int n)
{
    // Reverse the columns 
    for (int k = 0; k < n; k++)
    {
        int i = 0, j = n-1;
        while (i < j)
        {
            swap(a[k][i], a[k][j]);
            i++;
            j--;
        }
    }

    // cout << "Reversed Matrix : " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    // Transpose of the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i < j)
                swap(a[i][j], a[j][i]);
        }
    }

    cout << "Final Rotated Matrix : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate_stl(int a[][100], int n)
{
    //  STL reverse(start_container, end_container) 
    // Reverse the columns 
    for (int i = 0; i < n; i++)
    {
        reverse(a[i], a[i]+n);
    }

    // cout << "Reversed Matrix : " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    // Transpose of the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i < j)
                swap(a[i][j], a[j][i]);
        }
    }

    cout << "Final Rotated Matrix : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[100][100], n, count = 1;
    cin >> n;
    cout << "Orignal Matrix : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = count++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // rotate_transpose(a, n);
    rotate_stl(a, n);
    
    return 0;
}