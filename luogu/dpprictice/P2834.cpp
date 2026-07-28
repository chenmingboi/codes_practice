#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int>a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    vector<int>dp(w+1, 0);
    //凑出0有一种方案就是不用纸币
    dp[0] = 1;
    //只用前i种纸币
    // for(int i = 0;i < n;i++) {
    //     for(int j = w;j >= 0;j--) {
    //         //枚举用第i种纸币多少张，至少为1张要不然和dp[j]相同不应该更新
    //         for(int k = 1;k*a[i] <= j;k++) {
    //             dp[j] += dp[j-k*a[i]];
    //             dp[j] %= MOD;
    //         }
    //     }
    // }
    //更简单的写法直接就是完全背包
    for(int i = 0;i < n;i++) {
        for(int j = a[i];j <= w;j++) {
            dp[j] += dp[j-a[i]];
            dp[j] %= MOD;
        }
    }
    cout << dp[w];
    return 0;
}
