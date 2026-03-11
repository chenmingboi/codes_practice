#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    cout << a / __gcd(a, c)<< '/' << c / __gcd(a ,c); //cpp中__gcd函数用于求最大公约数
    return 0;
}