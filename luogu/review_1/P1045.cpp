#include<bits/stdc++.h>
using namespace std;

vector<int> large_mul(const vector<int>& a, const vector<int>& b) {
    int len1 = a.size(), len2 = b.size();
    vector<int>result(len1 + len2);
    for(int i = 0;i < len1;i++) {
        for(int j = 0;j < len2;j++) {
            result[i+j] += a[i] * b[j];
        }
    }
    int jinwei = 0;
    for(int i = 0;i < len1 + len2;i++) {
        result[i] += jinwei;
        jinwei = result[i] / 10;
        result[i] %= 10;
    }
    while(result.size() > 500 || result.back() == 0) result.pop_back();
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p;
    cin >> p;
    int weishu = p * log10(2) + 1;
    cout << weishu << endl;
    vector<int>result(1, 1), base(1, 2);
    //这里TLE，要使用快速幂
    // for(int i = 0;i < p;i++) {
    //     result = large_mul(result, 2);
    // }
    while(p) {
        if(p & 1) result = large_mul(result, base);
        base = large_mul(base, base);
        p >>= 1;
    }
    result[0] -= 1;
    result.resize(500);
    reverse(result.begin(), result.end());
    for(int i = 0;i < 500;i++) {
        cout << result[i];
        if(i != 0 && (i + 1) % 50 == 0) cout << endl;
    }
    return 0;
}