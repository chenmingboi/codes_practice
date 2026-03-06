#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int time1 = 5 * n, time2 = 11 + 3*n;
    if(time1 < time2) {
        cout << "Local";
    } else {
        cout << "Luogu";
    }
    return 0;
}