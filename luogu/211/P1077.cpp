#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e6+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    //dp[i][j]表示前i种花共摆放j盆的摆花方案
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= m;j++) {
            //表示第i种花摆放k盆
            for(int k = 0;k <= min(a[i], j);k++) {
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}