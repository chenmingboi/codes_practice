#include<bits/stdc++.h>
using namespace std;

//感觉可以用dp, 但是状态转移方程应该时什么呢？
//emmm 列举了前四项，貌似时dp[i] = 2 * dp[i-1] + 1
//写完发现运行样例和样例结果不一致，状态转移方程不对
//f[n]=f[n−1]+2f[n−2]+f[n−3]
//题目中说明结果可能很大，所以优先尝试使用高精度加法和乘法
//最后结果只要最后四位，所以可以在计算过程中 % 10000
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int MOD = 10000;
    vector<int>dp(n+1);
    vector<int>g(n+1);
    dp[0] = 1, dp[1] = 1;
    g[0] = 0, g[1] = 0;
    for(int i = 2;i <= n;i++) {
        dp[i] = (dp[i-1] + dp[i-2] + 2 * g[i-1]) % MOD;
        g[i] = (dp[i-2] + g[i-1]) % MOD;
    }
    cout << dp[n];
    return 0;
}