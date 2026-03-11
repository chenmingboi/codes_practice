#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int day = 1;
    while(a != 1) {
        a /= 2;
        day++;
    }
    cout << day;
    return 0;
}