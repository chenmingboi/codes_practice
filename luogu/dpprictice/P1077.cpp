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
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    //前i种花摆放0盆只有一种方案就是不摆
    for(int i = 0;i <= n;i++) dp[i][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            for(int k = 0;k <= a[i];k++) {
                if(j >= k) {
                    //前i-1种花摆放j-k盆，这里k可以取到0
                    dp[i][j] += dp[i-1][j-k];
                    dp[i][j] %= MOD;
                }
                //这里不加else因为当k>j的时候只是k不合法而不是第i种花就不能选
            }
        }
    }
    cout << dp[n][m];
    return 0;
}