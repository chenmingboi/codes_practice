#include<bits/stdc++.h>
using namespace std;

int main()
{
    int con1 = 0, con2 = 0, res1 = 0, res2 = 0, res3 = 0,
    res4 = 0, x = 0;
    cin >> x;
    if(x % 2 == 0 || x == 0) {
        con1 = 1;
    }
    if(x > 4 && x <= 12) {
        con2 = 1;
    }
    res1 = con1 & con2, res2 = con1 | con2, 
    res3 = con1 ^ con2, res4 = (con1 == 0 && con2 == 0);
    cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res4;
    return 0;
}