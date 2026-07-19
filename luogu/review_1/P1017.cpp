#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //在cpp中%运算对应的余数是和被除数的符号相同的
    // -3 % -2 = 1 mod -1
    //要把余数转换成非负数就需要把余数加上负的除数
    //-1 + -(-2) = 1 ,此时还需要把商进行对应的加一
    // 商 = 1 + 1 = 2，此时满足-3 = 2 * (-2) + 1
    int n, r, tempn;
    cin >> n >> r;
    tempn = n;
    string ans;
    //这里先做一次循环是为了防止n==0的情况，这个时候ans应该为0
    //如果不先做一次循环的话ans为空，答案不正确
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
    } while (n != 0);
    reverse(ans.begin(), ans.end());
    cout << tempn << '=';
    for(auto it : ans) {
        cout << it;
    }
    cout << "(base" << r << ')';
    return 0;
}