#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e6+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>a(n+1);
    //dp[i][j]表示用前i种花摆j盆的方案数
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i = 1;i <= n;i++) cin >> a[i]; 
    for(int i = 0;i <= n;i++) dp[i][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            for(int k = 0;k <= a[i];k++) {
                if(j >= k) {
                    dp[i][j] += dp[i-1][j-k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[n][m];
    return 0;
}