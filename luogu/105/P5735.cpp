#include<bits/stdc++.h>
using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double d1 = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    double d2 = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
    double d3 = sqrt(pow(x1-x3, 2) + pow(y1-y3, 2));
    cout << fixed << setprecision(2) << d1+d2+d3;
    return 0;
}