#include<bits/stdc++.h>
using namespace std;

//这道题想要考察的是函数式的推导，题目中的式子可以推出f_n = f_(n-1) + f_(n-2);斐波那契数列
int main(){
    int n;
    cin >> n;
    double f_n = (pow((1 + sqrt(5))/2, n) - pow((1 - sqrt(5))/2, n)) / sqrt(5);
    ostringstream oss;
    oss << fixed << setprecision(2) << f_n;
    cout << oss.str();
    return 0;
}