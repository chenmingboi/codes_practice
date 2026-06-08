#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int>a(n+1), dp(w+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    dp[0] = 1;
    //这里对应于二维dp的更新逻辑，外层更新的是i, 内层更新的是j
    //完全背包内层是从小到大遍历，0/1背包是从大到小遍历
    for(int i = 1;i <= n;i++) {
        for(int j = a[i];j <= w;j++) {
            dp[j] += dp[j-a[i]];
            dp[j] %= MOD;
        }
    }
    cout << dp[w];
    return 0;
}