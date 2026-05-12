#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //前置知识：最大公约数（gcd）和最小公倍数（lcm）的求法
    //两个数的积等于它们最大公约数和它们最小公倍数的积
    //a * b = gcd(a, b) * lcm(a, b)
    //c++中有自带的求gcd的函数为__gcd
    //这道题就要满足三个条件
    // x * y = p * q
    // gcd(p, q) = x
    // lcm(p, q) = y
    int x, y;
    long long mul;
    cin >> x >> y;
    mul = x * y;
    long long ans = 0;
    for(long long p = 1;p <= sqrt(mul);p++) {
        if(mul % p == 0) {
            //找到对应的q
            long long q = mul / p;
            if(__gcd(p, q) == x) {
                //如果__gcd(p, q) == x且x * y = p * q那么由于前置知识可以得到条件三也满足
                ans += (p == q) ? 1 : 2; //如果不相等, pq可以调换位置
            }
        }
    }
    cout << ans;
    return 0;
}