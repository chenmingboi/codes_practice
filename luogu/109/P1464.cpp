#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//使用记忆化存储，减少重复计算
unordered_map<string, ll>w;
ll digui(ll a, ll b, ll c) {
    string a_str = to_string(a), b_str = to_string(b), c_str = to_string(c);
    string str = a_str + "#" + b_str + "#" + c_str;
    if(w[str]) return w[str];
    if(a <= 0 || b <= 0 || c <= 0) return w[str] = 1;
    if(a > 20 || b > 20 || c > 20) return w[str] = digui(20, 20, 20);
    if(a < b && b < c) {
        return w[str] = digui(a, b, c-1) + digui(a, b-1, c-1) - digui(a, b-1, c);
    }
    return w[str] = digui(a-1, b, c) + digui(a-1, b-1, c) + digui(a-1, b, c-1)
            - digui(a-1, b-1, c-1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, c;
    while(cin >> a && cin >> b && cin >> c) {
        if(a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << digui(a, b, c) << endl;
    }
    return 0;
}