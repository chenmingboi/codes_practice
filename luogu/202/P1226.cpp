#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //这里a b p也最好定义为long long尤其是a，因为下面用到了a = a * a % p;a*a可能会超出int的范围
    long long a, b, p;
    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=';
    long long ans = 1;
    a %= p;//先减小a
    //例如b=10 b的二进制表示为1010
    //a^10 = a^8 * a^2
    while(b) {
        if(b & 1) {
            ans = ans * a % p;
        }
        //a进行倍增
        a = a * a % p;
        //b向右移一位
        b >>= 1;
    }
    cout << ans;
    return 0;
}