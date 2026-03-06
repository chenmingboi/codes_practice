#include<bits/stdc++.h>
using namespace std;

int main() 
{
    double a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    double p = (a + b + c) / 2.0;
    double result = sqrt(p * (p-a) * (p-b) * (p-c));
    cout << fixed <<setprecision(1) << result;
    return 0;
}