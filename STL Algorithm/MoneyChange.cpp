#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    // find minimum no of coins/notes required for transaction
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int money = 168;

    map<int, int> reqMoney;
    while(money > 0)
    {
        if(money > 2000){
            money -=2000;
            if (reqMoney.find(2000) == reqMoney.end()) 
                reqMoney.insert(make_pair(2000, 1));
            else 
                reqMoney[2000]++;
        }
        else if (money > 500){
            money -=500;
            if (reqMoney.find(500) == reqMoney.end()) 
                reqMoney.insert(make_pair(500, 1));
            else 
                reqMoney[500]++;
        }
        else if (money > 200){
            money -=200;
            if (reqMoney.find(200) == reqMoney.end()) 
                reqMoney.insert(make_pair(200, 1));
            else 
                reqMoney[200]++;
        }
        else if (money > 100){
            money -=100;
            if (reqMoney.find(100) == reqMoney.end()) 
                reqMoney.insert(make_pair(100, 1));
            else 
                reqMoney[100]++;
        }
        else if (money > 50){
            money -=50;
            if (reqMoney.find(50) == reqMoney.end()) 
                reqMoney.insert(make_pair(50, 1));
            else 
                reqMoney[50]++;
        }
        else if (money > 20){
            money -=20;
            if (reqMoney.find(20) == reqMoney.end()) 
                reqMoney.insert(make_pair(20, 1));
            else 
                reqMoney[20]++;
        }
        else if (money > 10){
            money -=10;
            if (reqMoney.find(10) == reqMoney.end()) 
                reqMoney.insert(make_pair(10, 1));
            else 
                reqMoney[10]++;
        }
        else if (money > 5){
            money -=5;
            if (reqMoney.find(5) == reqMoney.end()) 
                reqMoney.insert(make_pair(5, 1));
            else 
                reqMoney[5]++;
        }
        else if (money > 2){
            money -=2;
            if (reqMoney.find(2) == reqMoney.end()) 
                reqMoney.insert(make_pair(2, 1));
            else 
                reqMoney[2]++;
        }
        else if (money >= 1){
            money -=1;
            if (reqMoney.find(1) == reqMoney.end()) 
                reqMoney.insert(make_pair(1, 1));
            else 
                reqMoney[1]++;
        }
    };

    for (auto&  it: reqMoney)
    {
        cout << it.first << "x" << it.second << endl;
    }

    return 0;
}