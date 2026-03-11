#include<bits/stdc++.h>
using namespace std;

int main()
{
    double s;
    cin >> s;
    int step = 0;
    double swam = 2;
    double distance = 0.0;
    while(distance < s) {
        distance += swam;
        step++;
        swam *= 0.98;
    }
    cout << step;
    return 0;
}