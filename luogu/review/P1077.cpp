#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e6+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    //dp[i][j]表示用前i种花，一共排j盆花
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    //用前i朵花排0盆，方案数均为1
    for(int i = 0;i <= n;i++) dp[i][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            //用k朵第i种花
            for(int k = 0;k <= a[i];k++) {
                if(k <= j) {
                    //加上不用第i种花的方案
                    dp[i][j] += dp[i-1][j-k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[n][m];
    return 0;
}