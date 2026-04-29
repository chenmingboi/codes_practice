#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r, tempn;
    cin >> n >> r;
    tempn = n;
    //在 C++ 中：%的规则：余数的符号和被除数 a 相同
    //-3 % 2 = -1 但是在数学中余数一定是非负数
    //-3 = 1 * (-2) + (-1)
    //3 = (-1)*(-2) + 1
    string ans;
    do {
        int temp = n % r;
        n /= r;
        if(temp < 0) {
            temp += -r;
            n += 1;
        }
        if(temp >= 10) {
            ans += char(temp-10+'A');
        } else {
            ans += to_string(temp);
        }
    } while(n != 0);
    reverse(ans.begin(), ans.end());
    cout << tempn << '=' << ans << "(base" << r << ')';
    return 0;
}