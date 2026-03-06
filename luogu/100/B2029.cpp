#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h = 0, r = 0;
    cin >> h >> r;
    double con = 3.14 * pow(r, 2) * h;
    int result = ceil(20000 / con); //向上取整ceil, ml=cm^3
    cout << result;
    return 0;
}