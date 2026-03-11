#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, minCost = INT_MAX;
    cin >> n;
    for(int i = 0; i < 3;i++) {
        int num, price;
        cin >> num >> price;
        minCost = min(minCost, ((n + num - 1) / num) * price);
    }
    cout << minCost;
    return 0;
}