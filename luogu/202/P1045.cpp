#include<bits/stdc++.h>
using namespace std;

//这里由于需要乘2的很大次方，所以乘数b也需要用vector<int>
vector<int> mul_large(const vector<int>& a, const vector<int>& b) {
    //默认a是反着的
    int lena = a.size(), lenb = b.size();
    vector<int>result(lena + lenb, 0);
    for(int i = 0;i < lena;i++) {
        for(int j = 0;j < lenb;j++) {
            result[i+j] += a[i] * b[j];
        }
    }
    int jinwei = 0;
    for(int i = 0;i < lena + lenb;i++) {
        result[i] += jinwei;
        jinwei = result[i] / 10;
        result[i] %= 10;
    }
    while(!result.empty() && result.back() == 0) result.pop_back();
    result.resize(500);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p ,digit = 0;
    cin >> p;
    //2^p的位数即log_10 + 1的结果 eg2^2 = 4 log_10(4) + 1 = 0
    digit = int(p * log10(2) + 1);
    vector<int>base(1, 2), ans(1, 1);
    while(p) {
        //利用快速幂
        //10 = 1010(2) 2^10 = 2^8 * 2^2
        if(p & 1) ans = mul_large(ans, base);
        base = mul_large(base, base);
        p >>= 1;
    }
    cout << digit << endl;
    ans.resize(500);ans[0]-=1;
    int cnt = 0;
    for(int i = 499;i >= 0;i--) {
        cnt++;
        cout << ans[i];
        if(cnt == 50) {
            cout << endl;
            cnt = 0;
        }
    }
    return 0;
}