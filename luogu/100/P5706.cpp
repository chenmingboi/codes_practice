#include<bits/stdc++.h>
using namespace std;

int main() 
{
    double t;
    int n; //这里如果n用double反而有用例没法通过
    cin >> t >> n; 
    cout << fixed << setprecision(3) << t/n << endl;
    cout << n*2;
    return 0;
}