#include<iostream>
#include<vector>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    bool positive = true;
    cin >> n;
    positive = n < 0 ? false : true;
    vector<int> num;
    int tmp;
    if(positive)
    {
        while (n > 0){
            tmp = n % 10;
            num.push_back(tmp);
            n /= 10;
        }
    }
    else
    {
        while (n < 0) {
            tmp = (n % 10) * -1;
            num.push_back(tmp);
            n /= 10;
        }
    }
    
    int number = 0, p = 1;
    int i =0;
    if(positive)
    {
        for (; i < num.size()-1; i++)
        {        
            if(num[i] < 5)
                number += num[i] * p;
            else 
                number += (9 - num[i]) * p;
            p *= 10;
        }
        if(num[i] > 4 || num[i] == 9)
            number += (9 - num[i]) * p;
        else 
            number += num[i] * p;
    }
    else
    {
        for (; i < num.size()-1; i++)
        {        
            if(num[i] < 5)
                number += (9 - num[i]) * p;
            else 
                number += num[i] * p;
            p *= 10;
        }
        if(num[i] > 4 || num[i] == 9)
            number += num[i] * p;
        else 
            number += (9 - num[i]) * p;
    }
    


    if(!positive)
        cout << "-";
    cout << number;

    return 0;
}